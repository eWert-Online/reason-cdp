open Cmdliner;

Printexc.record_backtrace(true);

let get_file_contents = filename => {
  let ic = open_in_bin(filename);
  let file_length = in_channel_length(ic);
  let data = really_input_string(ic, file_length);
  close_in(ic);
  data;
};

let rec map_type = typ => {
  let prim =
    typ |> Yojson.Basic.Util.member("type") |> Yojson.Basic.Util.to_string;

  switch (prim) {
  | "integer" => "int"
  | "number" => "float"
  | "boolean" => "bool"
  | "any" => "string"
  | "array" => map_array(typ)
  | "object" => map_object(typ)
  | t => t
  };
}
and map_ref = typ => {
  let r =
    typ |> Yojson.Basic.Util.member("$ref") |> Yojson.Basic.Util.to_string;

  let is_exteral = String.contains(r, '.');
  if (is_exteral) {
    let l = r |> String.split_on_char('.');
    let head = l |> List.hd;
    let r =
      l
      |> List.tl
      |> List.append(["Types"])
      |> List.append([head])
      |> String.concat(".");
    r ++ ".t";
  } else {
    r ++ ".t";
  };
}
and map_array = typ => {
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
    "array(" ++ map_type(typ |> Yojson.Basic.Util.member("items")) ++ ")"
  | (None, Some(_reference)) =>
    "array(" ++ map_ref(typ |> Yojson.Basic.Util.member("items")) ++ ")"
  };
}
and map_object = typ => {
  let properties =
    typ
    |> Yojson.Basic.Util.member("properties")
    |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
    |> Option.map(
         List.map(prop => {
           let name =
             prop
             |> Yojson.Basic.Util.member("name")
             |> Yojson.Basic.Util.to_string
             |> (
               fun
               | "type" => "type_"
               | "object" => "object_"
               | "end" => "end_"
               | "exception" => "exception_"
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
             name ++ ": " ++ map_type(prop) ++ ", /* " ++ description ++ " */"
           | (None, Some(_reference)) =>
             name ++ ": " ++ map_ref(prop) ++ ", /* " ++ description ++ " */"
           };
         }),
       )
    |> Option.map(String.concat("\n"));

  switch (properties) {
  | None => "{. }"
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

  let type_ = map_type(typ);

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
    String.concat("\n", [id ++ ": {", content, "} = " ++ id]),
  );
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
  let write = output_string(out_channel);

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

      print_endline("Writing " ++ name);

      let signature = String.concat("\n", [types_s]);
      let body = String.concat("\n", [types_b]);

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
