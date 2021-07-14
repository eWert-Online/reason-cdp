open Cmdliner;

let get_file_contents = filename => {
  let ic = open_in_bin(filename);
  let file_length = in_channel_length(ic);
  let data = really_input_string(ic, file_length);
  close_in(ic);
  data;
};

let get_type = typ => {
  let id =
    typ |> Yojson.Basic.Util.member("id") |> Yojson.Basic.Util.to_string;

  let description =
    typ
    |> Yojson.Basic.Util.member("description")
    |> Yojson.Basic.Util.to_string_option
    |> Option.value(~default="No description provided");

  let type_ =
    typ
    |> Yojson.Basic.Util.member("type")
    |> Yojson.Basic.Util.to_string
    |> (
      fun
      | "object" => "{ test: string }"
      | "integer" => "int"
      | "number" => "float"
      | "array" => "array(int)"
      | t => t
    );

  String.concat(
    "\n",
    [
      id ++ ": {} = { ",
      "/* " ++ description ++ " */",
      "[@deriving yojson]",
      "type t = " ++ type_ ++ ";",
      "}",
    ],
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

      let types =
        domain
        |> Yojson.Basic.Util.member("types")
        |> Yojson.Basic.Util.to_option(Yojson.Basic.Util.to_list)
        |> Option.map(List.map(get_type))
        |> Option.map(String.concat("\n and "))
        |> (
          fun
          | None => ""
          | Some(types) => "module Types = { module rec " ++ types ++ "}"
        );

      print_endline("Writing " ++ name);

      let signature = "";
      let body = String.concat("\n", [types]);

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
