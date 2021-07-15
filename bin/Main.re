open Cmdliner;

Printexc.record_backtrace(true);

let get_file_contents = filename => {
  let ic = open_in_bin(filename);
  let file_length = in_channel_length(ic);
  let data = really_input_string(ic, file_length);
  close_in(ic);
  data;
};

let rec map_type = (~key="type", ~in_types, typ) => {
  let prim =
    typ |> Yojson.Basic.Util.member(key) |> Yojson.Basic.Util.to_string;

  switch (prim) {
  | "integer" => "float"
  | "number" => "float"
  | "boolean" => "bool"
  | "any" => "string"
  | "array" => map_array(typ, ~in_types)
  | "object" => map_object(typ, ~in_types)
  | t => t
  };
}
and map_ref = (~force_external=false, typ) => {
  let r =
    typ |> Yojson.Basic.Util.member("$ref") |> Yojson.Basic.Util.to_string;

  let has_path = String.contains(r, '.');

  let is_exteral = force_external || has_path;

  if (is_exteral && has_path) {
    let l = r |> String.split_on_char('.');
    let head = l |> List.hd;
    let r =
      l
      |> List.tl
      |> List.append(["Types"])
      |> List.append([head])
      |> String.concat(".");
    r ++ ".t";
  } else if (is_exteral) {
    "Types." ++ r ++ ".t";
  } else {
    r ++ ".t";
  };
}
and map_array = (typ, ~in_types) => {
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
    "array("
    ++ map_type(typ |> Yojson.Basic.Util.member("items"), ~in_types)
    ++ ")"
  | (None, Some(_reference)) =>
    "array("
    ++ map_ref(
         typ |> Yojson.Basic.Util.member("items"),
         ~force_external=!in_types,
       )
    ++ ")"
  };
}
and map_object = (~key="properties", ~in_types, typ) => {
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
             | (Some(_prim), None) => map_type(prop, ~in_types)
             | (None, Some(_reference)) =>
               map_ref(prop, ~force_external=!in_types)
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
  | None => "assoc"
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

let get_event = event => {
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

  let result =
    switch (parameters) {
    | None => "empty"
    | Some(_) => map_object(event, ~key="parameters", ~in_types=false)
    };

  let signature = [
    "/* " ++ description ++ " */",
    "module " ++ module_name ++ ": {",
    "  [@deriving yojson]",
    "  type result = " ++ result ++ ";",
    "",
    "  [@deriving yojson]",
    "  type t = {",
    "    method: string,",
    "    params: result,",
    "    sessionId: Target.Types.SessionID.t,",
    "  };",
    "",
    "  let parse: string => t;",
    "};",
  ];

  let content = [
    "/* " ++ description ++ " */",
    "module " ++ module_name ++ " = {",
    "  [@deriving yojson]",
    "  type result = " ++ result ++ ";",
    "",
    "  [@deriving yojson]",
    "  type t = {",
    "    method: string,",
    "    params: result,",
    "    sessionId: Target.Types.SessionID.t,",
    "  };",
    "",
    "  let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;",
    "};",
  ];

  (String.concat("\n", signature), String.concat("\n", content));
};

let main = (path, output) => {
  let protocol = get_file_contents(path) |> Yojson.Basic.from_string;
  let domains =
    protocol
    |> Yojson.Basic.Util.member("domains")
    |> Yojson.Basic.Util.to_list;

  let path = Filename.concat(output, "CDP.re");
  FileUtil.rm([path]);
  FileUtil.touch(path);

  let out_channel = open_out_bin(path);
  let write = s => output_string(out_channel, s ++ "\n");

  write(
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

      let (types_s, types_b) =
        domain
        |> Yojson.Basic.Util.member("types")
        |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
        |> Option.map(List.map(get_type))
        |> Option.map(t => {
             let (s, b) = List.split(t);
             (String.concat("\n and ", s), String.concat("\n and ", b));
           })
        |> (
          fun
          | None => ("", "")
          | Some((s, b)) => (
              "module Types: { module rec " ++ s ++ "};",
              "module Types: { module rec "
              ++ s
              ++ "} = { module rec "
              ++ b
              ++ " };",
            )
        );

      let (events_s, events_b) =
        domain
        |> Yojson.Basic.Util.member("events")
        |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
        |> Option.map(List.map(get_event))
        |> Option.map(t => {
             let (s, b) = List.split(t);
             (String.concat("\n", s), String.concat("\n", b));
           })
        |> (
          fun
          | None => ("", "")
          | Some((s, b)) => (
              "module Events: {" ++ s ++ "};",
              "module Events = {" ++ b ++ "};",
            )
        );

      print_endline("Writing " ++ name);

      let signature = String.concat("\n", [types_s, events_s]);
      let body = String.concat("\n", [types_b, events_b]);

      let module_definition =
        if (i == 0) {
          String.concat(
            "\n",
            ["module rec " ++ name ++ ": {", signature, "} = {", body, "}"],
          );
        } else {
          String.concat(
            "\n",
            [" and " ++ name ++ ": {", signature, "} = {", body, "}"],
          );
        };

      write(module_definition);
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

let file = {
  let doc = "A file to parse.";
  Arg.(value & pos(0, non_dir_file, "") & info([], ~docv="FILE", ~doc));
};

let output = {
  let doc = "The direcory, where to put the generated api";
  Arg.(value & pos(1, dir, "") & info([], ~docv="DIR", ~doc));
};

let cmd = Term.(const(main) $ file $ output);

let () = Term.exit @@ Term.eval((cmd, info));
