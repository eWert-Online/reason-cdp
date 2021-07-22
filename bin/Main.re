open Cmdliner;

Printexc.record_backtrace(true);

let get_file_contents = filename => {
  let ic = open_in_bin(filename);
  let file_length = in_channel_length(ic);
  let data = really_input_string(ic, file_length);
  close_in(ic);
  data;
};

let rec map_type =
        (~key="type", ~additional_ref_path_segment="", ~in_types, typ) => {
  let prim =
    typ |> Yojson.Basic.Util.member(key) |> Yojson.Basic.Util.to_string;

  switch (prim) {
  | "integer" => "float"
  | "number" => "float"
  | "boolean" => "bool"
  | "any" => "string"
  | "array" => map_array(typ, ~in_types, ~additional_ref_path_segment)
  | "object" => map_object(typ, ~in_types, ~additional_ref_path_segment)
  | t => t
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
and map_array = (~additional_ref_path_segment="", typ, ~in_types) => {
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
    (~key="properties", ~additional_ref_path_segment="", ~in_types, typ) => {
  let properties =
    typ
    |> Yojson.Basic.Util.member(key)
    |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
    |> Option.map(
         List.map(prop => {
           let name =
             prop
             |> Yojson.Basic.Util.member("name")
             |> Yojson.Basic.Util.to_string
             |> (
               fun
               | "type" => "[@key \"type\"] type_"
               | "object" => "[@key \"object\"] object_"
               | "end" => "[@key \"end\"] end_"
               | "exception" => "[@key \"exception\"] exception_"
               | "done" => "[@key \"done\"] done_"
               | t => t
             );

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
               map_type(prop, ~in_types, ~additional_ref_path_segment)
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

let get_type = typ => {
  let id =
    typ |> Yojson.Basic.Util.member("id") |> Yojson.Basic.Util.to_string;

  let description =
    typ
    |> Yojson.Basic.Util.member("description")
    |> Yojson.Basic.Util.to_string_option
    |> Option.value(~default="No description provided");

  let type_ = map_type(typ, ~in_types=true);

  let content =
    String.concat(
      "\n",
      [
        "/* " ++ description ++ " */",
        "[@deriving yojson]",
        "type t = " ++ type_ ++ ";",
      ],
    );

  (
    String.concat("\n", [id ++ ": {", content, "}"]),
    String.concat(
      "\n",
      [id ++ ": {", content, "} = ", "{ " ++ content ++ " }"],
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

  let result =
    switch (parameters) {
    | None => "Types.empty"
    | Some(_) =>
      map_object(
        event,
        ~key="parameters",
        ~in_types=false,
        ~additional_ref_path_segment=domain ++ ".",
      )
    };

  let content = [
    "/* " ++ description ++ " */",
    "module " ++ module_name ++ " = {",
    "  let name = \"" ++ key ++ "\";",
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

  let module_name = name |> String.capitalize_ascii;

  let key = domain ++ "." ++ name;

  let result =
    map_object(
      command,
      ~key="returns",
      ~in_types=false,
      ~additional_ref_path_segment=domain ++ ".",
    );

  let content = [
    "/* " ++ description ++ " */                                              ",
    "module " ++ module_name ++ " = {                                         ",
    "                                                                         ",
    "  module Response: {                                                     ",
    "    type result = " ++ result ++ ";                                      ",
    "                                                                         ",
    "    type t = {                                                           ",
    "      id: int,                                                           ",
    "      sessionId: option(Types.Target.SessionID.t),                       ",
    "      result: result,                                                    ",
    "    };                                                                   ",
    "                                                                         ",
    "    let parse: string => t;                                              ",
    "  } = {                                                                  ",
    "    [@deriving yojson]                                                   ",
    "    type result = " ++ result ++ ";                                      ",
    "                                                                         ",
    "    [@deriving yojson]                                                   ",
    "    type t = {                                                           ",
    "      id: int,                                                           ",
    "      [@yojson.option]                                                   ",
    "      sessionId: option(Types.Target.SessionID.t),                       ",
    "      result: result,                                                    ",
    "    };                                                                   ",
    "                                                                         ",
    "    let parse = response => {                                            ",
    "      response |> Yojson.Safe.from_string |> t_of_yojson;                ",
    "    };                                                                   ",
    "  };                                                                     ",
    "                                                                         ",
    switch (params) {
    | None => ""
    | Some(_) =>
      let args =
        switch (params) {
        | None => ""
        | Some(params) =>
          params
          |> List.map(param => {
               let name =
                 param
                 |> Yojson.Basic.Util.member("name")
                 |> Yojson.Basic.Util.to_string
                 |> (
                   fun
                   | "type" => "type_"
                   | "object" => "object_"
                   | "end" => "end_"
                   | "exception" => "exception_"
                   | "done" => "done_"
                   | t => t
                 );

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
          |> String.concat("\n")
        };
      String.concat(
        "",
        [
          "  module Params = {                                                ",
          "    [@deriving yojson]                                             ",
          "    type t =                                                       ",
          map_object(
            ~in_types=false,
            ~key="parameters",
            ~additional_ref_path_segment=domain ++ ".",
            command,
          ),
          "                                                                   ",
          "    let make = (" ++ args ++ " ()) => {                           ",
          switch (params) {
          | None => ""
          | Some(params) =>
            "{"
            ++ (
              params
              |> List.map(param => {
                   let name =
                     param
                     |> Yojson.Basic.Util.member("name")
                     |> Yojson.Basic.Util.to_string
                     |> (
                       fun
                       | "type" => "type_"
                       | "object" => "object_"
                       | "end" => "end_"
                       | "exception" => "exception_"
                       | "done" => "done_"
                       | t => t
                     );

                   name ++ ": " ++ name;
                 })
              |> String.concat(",")
            )
            ++ "}"
          },
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
