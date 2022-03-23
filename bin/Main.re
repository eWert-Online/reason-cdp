open Cmdliner;

Printexc.record_backtrace(true);

module String = {
  include String;
  let prefix = (prefix, s) => prefix ++ s;
};

let get_file_contents = filename => {
  let ic = open_in_bin(filename);
  let file_length = in_channel_length(ic);
  let data = really_input_string(ic, file_length);
  close_in(ic);
  data;
};

let map_reserved_words =
  fun
  | "open" => "open_"
  | "new" => "new_"
  | "with" => "with_"
  | "module" => "module_"
  | "object" => "object_"
  | "function" => "function_"
  | "type" => "type_"
  | "end" => "end_"
  | "exception" => "exception_"
  | "done" => "done_"
  | "assert" => "assert_"
  | s => s;

let rec map_type =
        (~key="type", ~additional_ref_path_segment="", ~enums, ~in_types, typ) => {
  let prim =
    typ |> Yojson.Basic.Util.member(key) |> Yojson.Basic.Util.to_string;

  let is_enum =
    typ
    |> Yojson.Basic.Util.member("enum")
    |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
    |> Option.is_some;

  switch (is_enum, enums) {
  | (true, Some(enums)) =>
    let (name, _) = Queue.take(enums);
    name;
  | (true, None) => failwith("Expected enums but didn't find any")
  | (false, enums) =>
    switch (prim) {
    | "integer" => in_types ? "number" : "Types.number"
    | "number" => in_types ? "number" : "Types.number"
    | "boolean" => "bool"
    | "any" => "string"
    | "array" =>
      map_array(typ, ~enums, ~in_types, ~additional_ref_path_segment)
    | "object" =>
      map_object(typ, ~enums, ~in_types, ~additional_ref_path_segment)
    | t => t
    }
  };
}
and map_ref = (~in_types, ~additional_path_segment="", typ) => {
  let r =
    typ |> Yojson.Basic.Util.member("$ref") |> Yojson.Basic.Util.to_string;

  let has_path = String.contains(r, '.');

  if (!in_types && has_path) {
    "Types." ++ r ++ ".t";
  } else if (!in_types) {
    "Types." ++ additional_path_segment ++ r ++ ".t";
  } else {
    additional_path_segment ++ r ++ ".t";
  };
}
and map_array = (~additional_ref_path_segment="", ~enums, ~in_types, typ) => {
  let prim =
    typ
    |> Yojson.Basic.Util.member("items")
    |> Yojson.Basic.Util.member("type")
    |> Yojson.Basic.Util.to_string_option;

  let reference =
    typ
    |> Yojson.Basic.Util.member("items")
    |> Yojson.Basic.Util.member("$ref")
    |> Yojson.Basic.Util.to_string_option;

  switch (prim, reference) {
  | (None, None) =>
    failwith("Unexpected array value: neither type nor $ref is present")
  | (Some(_), Some(_)) =>
    failwith("Unexpected array value: both type and $ref present")
  | (Some(_prim), None) =>
    "list("
    ++ map_type(
         typ |> Yojson.Basic.Util.member("items"),
         ~enums,
         ~in_types,
         ~additional_ref_path_segment,
       )
    ++ ")"
  | (None, Some(_reference)) =>
    "list("
    ++ map_ref(
         typ |> Yojson.Basic.Util.member("items"),
         ~in_types,
         ~additional_path_segment=additional_ref_path_segment,
       )
    ++ ")"
  };
}
and map_object =
    (
      ~key="properties",
      ~additional_ref_path_segment="",
      ~enums,
      ~in_types,
      typ,
    ) => {
  let properties =
    typ
    |> Yojson.Basic.Util.member(key)
    |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
    |> Option.map(
         List.map(prop => {
           let name =
             prop
             |> Yojson.Basic.Util.member("name")
             |> Yojson.Basic.Util.to_string;

           let name =
             name
             |> map_reserved_words
             |> String.prefix("[@key \"" ++ name ++ "\"]");

           let description =
             prop
             |> Yojson.Basic.Util.member("description")
             |> Yojson.Basic.Util.to_string_option
             |> Option.value(~default="No description provided");

           let reference =
             prop
             |> Yojson.Basic.Util.member("$ref")
             |> Yojson.Basic.Util.to_string_option;

           let prim =
             prop
             |> Yojson.Basic.Util.member("type")
             |> Yojson.Basic.Util.to_string_option;

           let optional =
             prop
             |> Yojson.Basic.Util.member("optional")
             |> Yojson.Basic.Util.to_bool_option
             |> Option.value(~default=false);

           let typ =
             switch (prim, reference) {
             | (None, None) =>
               failwith(
                 "Unexpected object property value: neither type nor $ref is present",
               )
             | (Some(_), Some(_)) =>
               failwith(
                 "Unexpected object property value: both type and $ref present",
               )
             | (Some(_prim), None) =>
               map_type(prop, ~enums, ~in_types, ~additional_ref_path_segment)
             | (None, Some(_reference)) =>
               map_ref(
                 prop,
                 ~in_types,
                 ~additional_path_segment=additional_ref_path_segment,
               )
             };

           if (optional) {
             "[@yojson.option]"
             ++ name
             ++ ": option("
             ++ typ
             ++ "), /* "
             ++ description
             ++ " */";
           } else {
             name ++ ": " ++ typ ++ ", /* " ++ description ++ " */";
           };
         }),
       )
    |> Option.map(String.concat("\n"));

  switch (properties) {
  | None => in_types ? "assoc" : "Types.assoc"
  | Some(p) => "{" ++ p ++ "}"
  };
};

let rec find_enums = (~path="", t) => {
  let id =
    t |> Yojson.Basic.Util.member("id") |> Yojson.Basic.Util.to_string_option;

  let name =
    t
    |> Yojson.Basic.Util.member("name")
    |> Yojson.Basic.Util.to_string_option;

  let path =
    switch (id, name) {
    | (None, None) => path
    | (Some(id), None) => String.concat("_", [path, id])
    | (None, Some(name)) => String.concat("_", [path, name])
    | (Some(id), Some(name)) => String.concat("_", [path, id, name])
    };
  let path = path |> String.lowercase_ascii;

  let enum =
    t
    |> Yojson.Basic.Util.member("enum")
    |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
    |> Option.map(
         List.map(enum => {
           let original = Yojson.Basic.Util.to_string(enum);
           let enum =
             original
             |> String.map(
                  fun
                  | '-' => '_'
                  | c => c,
                )
             |> map_reserved_words;

           (original, enum);
         }),
       );

  let properties =
    t
    |> Yojson.Basic.Util.member("properties")
    |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list);

  switch (enum, properties) {
  | (None, None) => []
  | (Some(enum), None) => [(path, enum)]
  | (None, Some(prop)) =>
    prop |> List.map(find_enums(~path)) |> List.flatten
  | (Some(enum), Some(prop)) => [
      (path, enum),
      ...prop |> List.map(find_enums(~path)) |> List.flatten,
    ]
  };
};

let get_enums = enums => {
  switch (enums) {
  | [] => ("", "")
  | enums =>
    let interface =
      enums
      |> List.map(((name, values)) => {
           let variants =
             values
             |> List.map(((_, v)) => "`" ++ v)
             |> String.concat(" | ");

           String.concat(
             "\n",
             [
               "type " ++ name ++ " = [" ++ variants ++ "];",
               "let "
               ++ name
               ++ "_of_yojson: Yojson.Basic.t => "
               ++ name
               ++ ";",
               "let yojson_of_"
               ++ name
               ++ ": "
               ++ name
               ++ " => Yojson.Basic.t;",
             ],
           );
         })
      |> String.concat("");

    let content =
      enums
      |> List.map(((name, values)) => {
           let variants =
             values
             |> List.map(((_, v)) => "`" ++ v)
             |> String.concat(" | ");

           let variants_to_yojson =
             values
             |> List.map(((original, enum)) => {
                  "| `" ++ enum ++ " => `String(\"" ++ original ++ "\")"
                })
             |> String.concat("\n");

           let yojson_to_variants =
             values
             |> List.map(((original, enum)) => {
                  "| `String(\"" ++ original ++ "\") => `" ++ enum ++ ""
                })
             |> List.append(
                  _,
                  [
                    "| `String(s) => failwith(\"unknown enum: \" ++ s)",
                    "| _ => failwith(\"unknown enum type\")",
                  ],
                )
             |> String.concat("\n");

           String.concat(
             "\n",
             [
               "type " ++ name ++ " = [" ++ variants ++ "];",
               "let "
               ++ name
               ++ "_of_yojson = fun "
               ++ yojson_to_variants
               ++ ";",
               "let yojson_of_"
               ++ name
               ++ " = fun "
               ++ variants_to_yojson
               ++ ";",
             ],
           );
         })
      |> String.concat("");

    (interface, content);
  };
};

let get_type = typ => {
  let id =
    typ |> Yojson.Basic.Util.member("id") |> Yojson.Basic.Util.to_string;

  let description =
    typ
    |> Yojson.Basic.Util.member("description")
    |> Yojson.Basic.Util.to_string_option
    |> Option.value(~default="No description provided");

  let enums = find_enums(typ);
  let (enums_i, enums_c) = get_enums(enums);

  let enums_queue = Queue.create();
  enums |> List.iter(Queue.add(_, enums_queue));

  let type_ = map_type(typ, ~enums=Some(enums_queue), ~in_types=true);

  let interface =
    String.concat(
      "\n",
      [
        enums_i,
        "/* " ++ description ++ " */",
        "[@deriving yojson]",
        "type t = " ++ type_ ++ ";",
      ],
    );

  let content =
    String.concat(
      "\n",
      [
        enums_c,
        "/* " ++ description ++ " */",
        "[@deriving yojson]",
        "type t = " ++ type_ ++ ";",
      ],
    );

  (
    String.concat("\n", [id ++ ": {", interface, "}"]),
    String.concat(
      "\n",
      [id ++ ": {", interface, "} = ", "{ " ++ content ++ " }"],
    ),
  );
};

let get_event = (~domain, event) => {
  let name =
    event |> Yojson.Basic.Util.member("name") |> Yojson.Basic.Util.to_string;

  let description =
    event
    |> Yojson.Basic.Util.member("description")
    |> Yojson.Basic.Util.to_string_option
    |> Option.value(~default="No description provided");

  let parameters =
    event
    |> Yojson.Basic.Util.member("parameters")
    |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list);

  let module_name = name |> String.capitalize_ascii;

  let key = domain ++ "." ++ name;

  let param_enums =
    switch (parameters) {
    | None => []
    | Some(params) =>
      params |> List.map(find_enums(~path=name)) |> List.flatten
    };

  let (_enums_i, enums_c) = get_enums(param_enums);

  let result =
    switch (parameters) {
    | None => "Types.empty"
    | Some(_) =>
      let enums_queue = Queue.create();
      param_enums |> List.iter(Queue.add(_, enums_queue));

      map_object(
        event,
        ~enums=Some(enums_queue),
        ~key="parameters",
        ~in_types=false,
        ~additional_ref_path_segment=domain ++ ".",
      );
    };

  let content = [
    "/* " ++ description ++ " */",
    "module " ++ module_name ++ " = {",
    "  let name = \"" ++ key ++ "\";",
    "",
    enums_c,
    "",
    "  [@deriving yojson]",
    "  type result = " ++ result ++ ";",
    "",
    "  [@deriving yojson]",
    "  type t = {",
    "    method: string,",
    "    params: result,",
    "    sessionId: Types.Target.SessionID.t,",
    "  };",
    "",
    "  let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;",
    "};",
  ];

  String.concat("\n", content);
};

let get_command = (~domain, command) => {
  let name =
    command |> Yojson.Basic.Util.member("name") |> Yojson.Basic.Util.to_string;

  let description =
    command
    |> Yojson.Basic.Util.member("description")
    |> Yojson.Basic.Util.to_string_option
    |> Option.value(~default="No description provided");

  let params =
    command
    |> Yojson.Basic.Util.member("parameters")
    |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list);

  let returns =
    command
    |> Yojson.Basic.Util.member("returns")
    |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list);

  let module_name = name |> String.capitalize_ascii;

  let key = domain ++ "." ++ name;

  let returns_enums =
    switch (returns) {
    | None => []
    | Some(returns) =>
      returns |> List.map(find_enums(~path=name)) |> List.flatten
    };

  let (enums_i, enums_c) = get_enums(returns_enums);

  let returns_enums_queue = Queue.create();
  returns_enums |> List.iter(Queue.add(_, returns_enums_queue));

  let result =
    map_object(
      command,
      ~enums=Some(returns_enums_queue),
      ~key="returns",
      ~in_types=false,
      ~additional_ref_path_segment=domain ++ ".",
    );

  let content = [
    "/* " ++ description ++ " */                                              ",
    "module " ++ module_name ++ " = {                                         ",
    "                                                                         ",
    "  module Response: {                                                     ",
    enums_i,
    "",
    "    type result = " ++ result ++ ";                                      ",
    "                                                                         ",
    "    type error = {                                                       ",
    "        code: int,                                                       ",
    "        message: string,                                                 ",
    "    };                                                                   ",
    "                                                                         ",
    "    type t = {                                                           ",
    "      id: int,                                                           ",
    "      error: option(error),                                              ",
    "      sessionId: option(Types.Target.SessionID.t),                       ",
    "      result: option(result),                                                    ",
    "    };                                                                   ",
    "                                                                         ",
    "    let parse: string => t;                                              ",
    "  } = {                                                                  ",
    enums_c,
    "",
    "    [@deriving yojson]                                                   ",
    "    type result = " ++ result ++ ";                                      ",
    "                                                                         ",
    "    [@deriving yojson]                                                   ",
    "    type error = {                                                       ",
    "        code: int,                                                       ",
    "        message: string,                                                 ",
    "    };                                                                   ",
    "                                                                         ",
    "    [@deriving yojson]                                                   ",
    "    type t = {                                                           ",
    "      id: int,                                                           ",
    "      [@yojson.option]                                                   ",
    "      error: option(error),                                              ",
    "      [@yojson.option]                                                   ",
    "      sessionId: option(Types.Target.SessionID.t),                       ",
    "      [@yojson.option]                                                   ",
    "      result: option(result),                                            ",
    "    };                                                                   ",
    "                                                                         ",
    "    let parse = response => {                                            ",
    "      response |> Yojson.Safe.from_string |> t_of_yojson;                ",
    "    };                                                                   ",
    "  };                                                                     ",
    "                                                                         ",
    switch (params) {
    | None => ""
    | Some(params) =>
      let param_enums =
        params |> List.map(find_enums(~path=name)) |> List.flatten;

      let (_enums_i, enums_c) = get_enums(param_enums);

      let enums_queue = Queue.create();
      param_enums |> List.iter(Queue.add(_, enums_queue));

      let args =
        params
        |> List.map(param => {
             let name =
               param
               |> Yojson.Basic.Util.member("name")
               |> Yojson.Basic.Util.to_string
               |> map_reserved_words;

             let optional =
               param
               |> Yojson.Basic.Util.member("optional")
               |> Yojson.Basic.Util.to_bool_option
               |> Option.value(~default=false);

             if (optional) {
               "~" ++ name ++ "=?,";
             } else {
               "~" ++ name ++ ",";
             };
           })
        |> String.concat("\n");

      String.concat(
        "",
        [
          "  module Params = {                                                ",
          enums_c,
          "    [@deriving yojson]                                             ",
          "    type t =                                                       ",
          map_object(
            ~in_types=false,
            ~enums=Some(enums_queue),
            ~key="parameters",
            ~additional_ref_path_segment=domain ++ ".",
            command,
          ),
          "                                                                   ",
          "    let make = (" ++ args ++ " ()) => {                           ",
          "{"
          ++ (
            params
            |> List.map(param => {
                 let name =
                   param
                   |> Yojson.Basic.Util.member("name")
                   |> Yojson.Basic.Util.to_string
                   |> map_reserved_words;

                 name ++ ": " ++ name;
               })
            |> String.concat(",")
          )
          ++ "}",
          "    };                                                             ",
          "  };                                                               ",
        ],
      );
    },
    "                                                                         ",
    "  module Request = {                                                     ",
    "    [@deriving yojson]                                                   ",
    "    type t = {                                                           ",
    "      id: int,                                                           ",
    "      [@yojson.option]                                                   ",
    "      sessionId: option(Types.Target.SessionID.t),                       ",
    "      method: string,                                                    ",
    Option.is_some(params) ? "params: Params.t," : "",
    "    };                                                                   ",
    "                                                                         ",
    "    let make = (                                                         ",
    "      ~sessionId=?,                                                      ",
    Option.is_some(params) ? "~params," : "",
    "      id                                                                 ",
    "    ) => {                                                               ",
    "      ({                                                                 ",
    "        id: id,                                                          ",
    "        method: \"" ++ key ++ "\",                                       ",
    "        sessionId,                                                       ",
    Option.is_some(params) ? "params," : "",
    "      }) |> yojson_of_t |> Yojson.Safe.to_string;                        ",
    "    };                                                                   ",
    "  };                                                                     ",
    "};                                                                       ",
  ];

  String.concat("\n", content);
};

let main = (paths, output) => {
  let protocols =
    paths
    |> List.map(path => get_file_contents(path) |> Yojson.Basic.from_string);
  let domains =
    protocols
    |> List.map(protocol =>
         protocol
         |> Yojson.Basic.Util.member("domains")
         |> Yojson.Basic.Util.to_list
       )
    |> List.flatten;

  let path_types = Filename.concat(output, "Types.re");
  let path_events = Filename.concat(output, "Events.re");
  let path_commands = Filename.concat(output, "Commands.re");
  FileUtil.rm([path_types, path_events, path_commands]);

  FileUtil.touch(path_types);
  let out_types = open_out_bin(path_types);
  let write_types = s => output_string(out_types, s ++ "\n");

  FileUtil.touch(path_events);
  let out_events = open_out_bin(path_events);
  let write_events = s => output_string(out_events, s ++ "\n");

  FileUtil.touch(path_commands);
  let out_commands = open_out_bin(path_commands);
  let write_commands = s => output_string(out_commands, s ++ "\n");

  write_types(
    {ct|
      [@deriving yojson]
      type empty;

      type number = [ `Int(int) | `Float(float) ];
      let number_of_yojson =
        fun
        | `Float(f) when Float.is_integer(f) => `Int(int_of_float(f))
        | `Float(f) => `Float(f)
        | `Int(i) => `Int(i)
        | _ => failwith("Not a number");

      let yojson_of_number = number => {
        switch (number) {
          | `Float(f) => `Float(f)
          | `Int(i) => `Int(i)
        }
      };

      type assoc = list((string, string));
      let assoc_of_yojson =
        fun
        | `Assoc(l) => {
            l |> List.map(((key, value)) => (key, string_of_yojson(value)));
          }
        | _ => [];

      let yojson_of_assoc = assoc => {
        `Assoc(
          assoc |> List.map(((key, value)) => (key, yojson_of_string(value))),
        );
      };
    |ct},
  );

  List.iteri(
    (i, domain) => {
      let name =
        domain
        |> Yojson.Basic.Util.member("domain")
        |> Yojson.Basic.Util.to_string;

      print_endline("Writing Types: " ++ name);

      domain
      |> Yojson.Basic.Util.member("types")
      |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
      |> Option.map(List.map(get_type))
      |> Option.iter(t => {
           let (s, b) = List.split(t);
           let s = "module rec " ++ String.concat("\n and ", s);
           let b = "module rec " ++ String.concat("\n and ", b);
           if (i == 0) {
             write_types(
               "module rec " ++ name ++ ": {" ++ s ++ "} = {" ++ b ++ "}",
             );
           } else {
             write_types(
               " and " ++ name ++ ": {" ++ s ++ "} = {" ++ b ++ "}",
             );
           };
         });

      print_endline("Writing Events: " ++ name);

      domain
      |> Yojson.Basic.Util.member("events")
      |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
      |> Option.map(List.map(get_event(~domain=name)))
      |> Option.iter(b => {
           write_events(
             "module " ++ name ++ " {" ++ String.concat("\n", b) ++ "};",
           )
         });

      print_endline("Writing Commands: " ++ name);

      domain
      |> Yojson.Basic.Util.member("commands")
      |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
      |> Option.map(List.map(get_command(~domain=name)))
      |> Option.iter(b => {
           write_commands(
             "module " ++ name ++ " {" ++ String.concat("\n", b) ++ "};",
           )
         });
    },
    domains,
  );
};

let info = {
  let doc = "Parses CDP Protocols";
  Term.info(
    "CDP",
    ~doc,
    ~exits=
      Term.[
        exit_info(0, ~doc="if all files were parsed successfully."),
        exit_info(1, ~doc="on parsing errors."),
        exit_info(124, ~doc="on command line parsing errors."),
        exit_info(125, ~doc="on unexpected internal errors."),
      ],
  );
};

let protocols = {
  let doc = "A list protocols to parse.";
  Arg.(
    non_empty
    & pos_left(~rev=true, 0, non_dir_file, [])
    & info([], ~docv="PROTOCOL(S)", ~doc)
  );
};

let output = {
  let doc = "The direcory, where to put the generated api";
  Arg.(
    required
    & pos(~rev=true, 0, some(dir), None)
    & info([], ~docv="DIR", ~doc)
  );
};

let cmd = Term.(const(main) $ protocols $ output);

let () = Term.exit @@ Term.eval((cmd, info));
