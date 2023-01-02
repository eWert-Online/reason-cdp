open Cmdliner

let () = Printexc.record_backtrace true

let get_file_contents filename =
  let ic = open_in_bin filename in
  let file_length = in_channel_length ic in
  let data = really_input_string ic file_length in
  close_in ic;
  data

let map_reserved_words = function
  | "open" -> "open_"
  | "method" -> "method_"
  | "new" -> "new_"
  | "with" -> "with_"
  | "module" -> "module_"
  | "object" -> "object_"
  | "function" -> "function_"
  | "type" -> "type_"
  | "end" -> "end_"
  | "exception" -> "exception_"
  | "done" -> "done_"
  | "assert" -> "assert_"
  | s -> s

let rec map_type ?(key = "type") ?(additional_ref_path_segment = "") ~enums
    ~in_types typ =
  let prim =
    typ |> Yojson.Basic.Util.member key |> Yojson.Basic.Util.to_string
  in
  let is_enum =
    typ
    |> Yojson.Basic.Util.member "enum"
    |> Yojson.Basic.Util.to_option Yojson.Basic.Util.to_list
    |> Option.is_some
  in
  match (is_enum, enums) with
  | true, Some enums ->
      let name, _ = Queue.take enums in
      name
  | true, None -> failwith "Expected enums but didn't find any"
  | false, enums -> (
      match prim with
      | "integer" -> (
          match in_types with true -> "number" | false -> "Types.number")
      | "number" -> (
          match in_types with true -> "number" | false -> "Types.number")
      | "boolean" -> "bool"
      | "any" -> "string"
      | "array" -> map_array typ ~enums ~in_types ~additional_ref_path_segment
      | "object" -> map_object typ ~enums ~in_types ~additional_ref_path_segment
      | t -> t)

and map_ref ~in_types ?(additional_path_segment = "") typ =
  let r =
    typ |> Yojson.Basic.Util.member "$ref" |> Yojson.Basic.Util.to_string
  in
  let has_path = String.contains r '.' in
  if (not in_types) && has_path then "Types." ^ r ^ ".t"
  else if not in_types then "Types." ^ additional_path_segment ^ r ^ ".t"
  else additional_path_segment ^ r ^ ".t"

and map_array ?(additional_ref_path_segment = "") ~enums ~in_types typ =
  let prim =
    typ
    |> Yojson.Basic.Util.member "items"
    |> Yojson.Basic.Util.member "type"
    |> Yojson.Basic.Util.to_string_option
  in
  let reference =
    typ
    |> Yojson.Basic.Util.member "items"
    |> Yojson.Basic.Util.member "$ref"
    |> Yojson.Basic.Util.to_string_option
  in
  match (prim, reference) with
  | None, None ->
      failwith "Unexpected array value: neither type nor $ref is present"
  | Some _, Some _ ->
      failwith "Unexpected array value: both type and $ref present"
  | Some _prim, None ->
      map_type
        (typ |> Yojson.Basic.Util.member "items")
        ~enums ~in_types ~additional_ref_path_segment
      ^ " list"
  | None, Some _reference ->
      map_ref
        (typ |> Yojson.Basic.Util.member "items")
        ~in_types ~additional_path_segment:additional_ref_path_segment
      ^ " list"

and map_object ?(key = "properties") ?(additional_ref_path_segment = "") ~enums
    ~in_types typ =
  let properties =
    typ
    |> Yojson.Basic.Util.member key
    |> Yojson.Basic.Util.to_option Yojson.Basic.Util.to_list
    |> Option.map
         (List.map (fun prop ->
              let name =
                prop
                |> Yojson.Basic.Util.member "name"
                |> Yojson.Basic.Util.to_string
              in
              let key = name |> map_reserved_words in
              let description =
                prop
                |> Yojson.Basic.Util.member "description"
                |> Yojson.Basic.Util.to_string_option
                |> Option.value ~default:"No description provided"
              in
              let reference =
                prop
                |> Yojson.Basic.Util.member "$ref"
                |> Yojson.Basic.Util.to_string_option
              in
              let prim =
                prop
                |> Yojson.Basic.Util.member "type"
                |> Yojson.Basic.Util.to_string_option
              in
              let optional =
                prop
                |> Yojson.Basic.Util.member "optional"
                |> Yojson.Basic.Util.to_bool_option
                |> Option.value ~default:false
              in
              let typ =
                match (prim, reference) with
                | None, None ->
                    failwith
                      "Unexpected object property value: neither type nor $ref \
                       is present"
                | Some _, Some _ ->
                    failwith
                      "Unexpected object property value: both type and $ref \
                       present"
                | Some _prim, None ->
                    map_type prop ~enums ~in_types ~additional_ref_path_segment
                | None, Some _reference ->
                    map_ref prop ~in_types
                      ~additional_path_segment:additional_ref_path_segment
              in
              Printf.sprintf
                (if optional then
                 "%s: %s option [@key \"%s\"] [@yojson.option] [@ocaml.doc \
                  \"%s\"];"
                else "%s: %s [@key \"%s\"] [@ocaml.doc \"%s\"];")
                key typ name
                (String.escaped description)))
    |> Option.map (String.concat "\n")
  in
  match properties with
  | None -> ( match in_types with true -> "assoc" | false -> "Types.assoc")
  | Some p -> "{" ^ p ^ "}"

let rec find_enums ?(path = "") t =
  let id =
    t |> Yojson.Basic.Util.member "id" |> Yojson.Basic.Util.to_string_option
  in
  let name =
    t |> Yojson.Basic.Util.member "name" |> Yojson.Basic.Util.to_string_option
  in
  let path =
    match (id, name) with
    | None, None -> path
    | Some id, None -> String.concat "_" [ path; id ]
    | None, Some name -> String.concat "_" [ path; name ]
    | Some id, Some name -> String.concat "_" [ path; id; name ]
  in
  let path = path |> String.lowercase_ascii in
  let enum =
    t
    |> Yojson.Basic.Util.member "enum"
    |> Yojson.Basic.Util.to_option Yojson.Basic.Util.to_list
    |> Option.map
         (List.map (fun enum ->
              let original = Yojson.Basic.Util.to_string enum in
              let enum =
                original
                |> String.map (function '-' -> '_' | c -> c)
                |> map_reserved_words
              in
              (original, enum)))
  in
  let properties =
    t
    |> Yojson.Basic.Util.member "properties"
    |> Yojson.Basic.Util.to_option Yojson.Basic.Util.to_list
  in
  match (enum, properties) with
  | None, None -> []
  | Some enum, None -> [ (path, enum) ]
  | None, Some prop -> prop |> List.map (find_enums ~path) |> List.flatten
  | Some enum, Some prop ->
      (path, enum) :: (prop |> List.map (find_enums ~path) |> List.flatten)

let get_enums enums =
  match enums with
  | [] -> ("", "")
  | enums ->
      let interface =
        enums
        |> List.map (fun (name, values) ->
               let variants =
                 values
                 |> List.map (fun (_, v) -> "`" ^ v)
                 |> String.concat " | "
               in
               Printf.sprintf
                 {|
              type %s = [%s]
              val %s_of_yojson : Yojson.Basic.t -> %s
              val yojson_of_%s : %s -> Yojson.Basic.t
             |}
                 name variants name name name name)
        |> String.concat "\n"
      in
      let content =
        enums
        |> List.map (fun (name, values) ->
               let variants =
                 values
                 |> List.map (fun (_, v) -> "`" ^ v)
                 |> String.concat " | "
               in
               let variants_to_yojson =
                 values
                 |> List.map (fun (original, enum) ->
                        "| `" ^ enum ^ " -> `String (\"" ^ original ^ "\")")
                 |> String.concat "\n"
               in
               let yojson_to_variants =
                 values
                 |> List.map (fun (original, enum) ->
                        "| `String \"" ^ original ^ "\" -> `" ^ enum)
                 |> (fun __x ->
                      List.append __x
                        [
                          "| `String s -> failwith (\"unknown enum: \" ^ s)";
                          "| _ -> failwith \"unknown enum type\"";
                        ])
                 |> String.concat "\n"
               in
               String.concat "\n"
                 [
                   "type " ^ name ^ " = [" ^ variants ^ "]";
                   "let " ^ name ^ "_of_yojson = function " ^ yojson_to_variants
                   ^ ";;";
                   "let yojson_of_" ^ name ^ " = function " ^ variants_to_yojson
                   ^ ";;";
                 ])
        |> String.concat ""
      in
      (interface, content)

let get_type typ =
  let id =
    typ |> Yojson.Basic.Util.member "id" |> Yojson.Basic.Util.to_string
  in
  let description =
    typ
    |> Yojson.Basic.Util.member "description"
    |> Yojson.Basic.Util.to_string_option
    |> Option.value ~default:"No description provided"
  in
  let enums = find_enums typ in
  let enums_i, enums_c = get_enums enums in
  let enums_queue = Queue.create () in
  enums |> List.iter (fun __x -> Queue.add __x enums_queue);
  let type_ = map_type typ ~enums:(Some enums_queue) ~in_types:true in
  let interface =
    String.concat "\n"
      [
        enums_i;
        "type t = " ^ type_ ^ " [@@deriving yojson]  [@@ocaml.doc \""
        ^ String.escaped description ^ "\"]";
      ]
  in
  let content =
    String.concat "\n"
      [
        enums_c;
        "type t = " ^ type_ ^ " [@@deriving yojson] [@@ocaml.doc \""
        ^ String.escaped description ^ "\"]";
      ]
  in
  ( String.concat "\n" [ id ^ ": sig "; interface; " end" ],
    String.concat "\n"
      [ id ^ ": sig "; interface; " end = "; " struct " ^ content ^ " end" ] )

let get_event ~domain event =
  let name =
    event |> Yojson.Basic.Util.member "name" |> Yojson.Basic.Util.to_string
  in
  let description =
    event
    |> Yojson.Basic.Util.member "description"
    |> Yojson.Basic.Util.to_string_option
    |> Option.value ~default:"No description provided"
  in
  let parameters =
    event
    |> Yojson.Basic.Util.member "parameters"
    |> Yojson.Basic.Util.to_option Yojson.Basic.Util.to_list
  in
  let module_name = name |> String.capitalize_ascii in
  let key = domain ^ "." ^ name in
  let param_enums =
    match parameters with
    | None -> []
    | Some params -> params |> List.map (find_enums ~path:name) |> List.flatten
  in
  let _enums_i, enums_c = get_enums param_enums in
  let result =
    match parameters with
    | None -> "Types.empty"
    | Some _ ->
        let enums_queue = Queue.create () in
        param_enums |> List.iter (fun __x -> Queue.add __x enums_queue);
        map_object event ~enums:(Some enums_queue) ~key:"parameters"
          ~in_types:false ~additional_ref_path_segment:(domain ^ ".")
  in
  let content =
    [
      "(* " ^ description ^ " *)";
      "module " ^ module_name ^ " = struct";
      "  let name = \"" ^ key ^ "\"";
      "";
      enums_c;
      "";
      "  type result = " ^ result ^ " [@@deriving yojson]";
      "";
      "  type t = {";
      "    method_: string [@key \"method\"];";
      "    params: result;";
      "    sessionId: Types.Target.SessionID.t;";
      "  } [@@deriving yojson]";
      "";
      "  let parse event = event |> Yojson.Safe.from_string |> t_of_yojson;;";
      "end";
    ]
  in
  String.concat "\n" content

let get_command ~domain command =
  let name =
    command |> Yojson.Basic.Util.member "name" |> Yojson.Basic.Util.to_string
  in
  let description =
    command
    |> Yojson.Basic.Util.member "description"
    |> Yojson.Basic.Util.to_string_option
    |> Option.value ~default:"No description provided"
  in
  let params =
    command
    |> Yojson.Basic.Util.member "parameters"
    |> Yojson.Basic.Util.to_option Yojson.Basic.Util.to_list
  in
  let returns =
    command
    |> Yojson.Basic.Util.member "returns"
    |> Yojson.Basic.Util.to_option Yojson.Basic.Util.to_list
  in
  let module_name = name |> String.capitalize_ascii in
  let key = domain ^ "." ^ name in
  let returns_enums =
    match returns with
    | None -> []
    | Some returns ->
        returns |> List.map (find_enums ~path:name) |> List.flatten
  in
  let enums_i, enums_c = get_enums returns_enums in
  let returns_enums_queue = Queue.create () in
  returns_enums |> List.iter (fun __x -> Queue.add __x returns_enums_queue);
  let result =
    map_object command ~enums:(Some returns_enums_queue) ~key:"returns"
      ~in_types:false ~additional_ref_path_segment:(domain ^ ".")
  in
  let content =
    [
      "(* " ^ description ^ " *)";
      "module " ^ module_name ^ " = struct";
      "";
      "  module Response : sig";
      enums_i;
      "";
      "    type result = " ^ result;
      "";
      "    type error = {";
      "        code: int;";
      "        message: string;";
      "    }";
      "";
      "    type t = {";
      "      id: int;";
      "      error: error option;";
      "      sessionId: Types.Target.SessionID.t option;";
      "      result: result option;";
      "    }";
      "";
      "    val parse : string -> t";
      "  end = struct ";
      enums_c;
      "";
      "    type result = " ^ result ^ " [@@deriving yojson]";
      "";
      "    type error = {";
      "        code: int;";
      "        message: string;";
      "    } [@@deriving yojson]";
      "";
      "    type t = {";
      "      id: int";
      "    ; error: error option [@yojson.option]";
      "    ; sessionId: Types.Target.SessionID.t option [@yojson.option]";
      "    ; result: result option [@yojson.option]";
      "    } [@@deriving yojson]";
      "";
      "    let parse response = response |> Yojson.Safe.from_string |> \
       t_of_yojson;;";
      "  end";
      "";
      (match params with
      | None -> ""
      | Some params ->
          let param_enums =
            params |> List.map (find_enums ~path:name) |> List.flatten
          in
          let _enums_i, enums_c = get_enums param_enums in
          let enums_queue = Queue.create () in
          param_enums |> List.iter (fun __x -> Queue.add __x enums_queue);
          let args =
            params
            |> List.map (fun param ->
                   let name =
                     param
                     |> Yojson.Basic.Util.member "name"
                     |> Yojson.Basic.Util.to_string |> map_reserved_words
                   in
                   let optional =
                     param
                     |> Yojson.Basic.Util.member "optional"
                     |> Yojson.Basic.Util.to_bool_option
                     |> Option.value ~default:false
                   in
                   if optional then "?(" ^ name ^ ") " else "~" ^ name)
            |> String.concat "\n"
          in
          String.concat ""
            [
              "  module Params = struct ";
              enums_c;
              "    type t =";
              map_object ~in_types:false ~enums:(Some enums_queue)
                ~key:"parameters" ~additional_ref_path_segment:(domain ^ ".")
                command;
              " [@@deriving yojson]";
              "    let make " ^ args ^ " () = (";
              "      {"
              ^ (params
                |> List.map (fun param ->
                       let name =
                         param
                         |> Yojson.Basic.Util.member "name"
                         |> Yojson.Basic.Util.to_string |> map_reserved_words
                       in
                       name ^ " = " ^ name)
                |> String.concat ";")
              ^ "      }";
              "    );;";
              "end";
            ]);
      "";
      "  module Request = struct";
      "    type t = \
       {                                                           ";
      "      id: int;";
      "      sessionId: Types.Target.SessionID.t option [@yojson.option];";
      "      method_: string [@key \"method\"];";
      (match Option.is_some params with
      | true -> "params: Params.t;"
      | false -> "");
      "    } [@@deriving yojson]";
      "";
      "    let make ?sessionId ";
      (match Option.is_some params with true -> "~params " | false -> "");
      "    id";
      "    =";
      "      ({";
      "        id;";
      "        method_ = \"" ^ key ^ "\";";
      "        sessionId;";
      (match Option.is_some params with true -> "params;" | false -> "");
      "      }) |> yojson_of_t |> Yojson.Safe.to_string";
      "    ;;";
      "  end";
      "end";
    ]
  in
  String.concat "\n" content

let main paths output =
  let protocols =
    paths
    |> List.map (fun path -> get_file_contents path |> Yojson.Basic.from_string)
  in
  let domains =
    protocols
    |> List.map (fun protocol ->
           protocol
           |> Yojson.Basic.Util.member "domains"
           |> Yojson.Basic.Util.to_list)
    |> List.flatten
  in
  let path_types = Filename.concat output "Types.ml" in
  let path_events = Filename.concat output "Events.ml" in
  let path_commands = Filename.concat output "Commands.ml" in
  FileUtil.rm [ path_types; path_events; path_commands ];
  FileUtil.touch path_types;
  let out_types = open_out_bin path_types in
  let write_types s = output_string out_types (s ^ "\n") in
  FileUtil.touch path_events;
  let out_events = open_out_bin path_events in
  let write_events s = output_string out_events (s ^ "\n") in
  FileUtil.touch path_commands;
  let out_commands = open_out_bin path_commands in
  let write_commands s = output_string out_commands (s ^ "\n") in
  write_types
    {ct|
      type empty [@@deriving yojson]
      type number = [ `Int of int | `Float of float ]

      let number_of_yojson =
        function
        | `Float f when Float.is_integer f -> `Int (int_of_float f)
        | `Float f -> `Float f
        | `Int i -> `Int i
        | _ -> failwith "Not a number"
      ;;

      let yojson_of_number = function
        | `Float f -> `Float f
        | `Int i -> `Int i
      ;;

      type assoc = (string * string) list
      let assoc_of_yojson =
        function
        | `Assoc l -> l |> List.map(fun (key, value) -> (key, string_of_yojson value))
        | _ -> []
      ;;

      let yojson_of_assoc assoc =
        `Assoc (assoc |> List.map(fun (key, value) -> (key, yojson_of_string value)));
      ;;
    |ct};
  List.iteri
    (fun i domain ->
      let name =
        domain
        |> Yojson.Basic.Util.member "domain"
        |> Yojson.Basic.Util.to_string
      in
      print_endline ("Writing Types: " ^ name);
      domain
      |> Yojson.Basic.Util.member "types"
      |> Yojson.Basic.Util.to_option Yojson.Basic.Util.to_list
      |> Option.map (List.map get_type)
      |> Option.iter (fun t ->
             let s, b = List.split t in
             let s = "module rec " ^ String.concat "\n and " s in
             let b = "module rec " ^ String.concat "\n and " b in
             if i = 0 then
               write_types
                 ("module rec " ^ name ^ ": sig " ^ s ^ " end = struct " ^ b
                ^ " end")
             else
               write_types
                 (" and " ^ name ^ ": sig " ^ s ^ " end = struct " ^ b ^ " end"));
      print_endline ("Writing Events: " ^ name);
      domain
      |> Yojson.Basic.Util.member "events"
      |> Yojson.Basic.Util.to_option Yojson.Basic.Util.to_list
      |> Option.map (List.map (get_event ~domain:name))
      |> Option.iter (fun b ->
             write_events
               ("module " ^ name ^ " = struct " ^ String.concat "\n" b ^ " end"));
      print_endline ("Writing Commands: " ^ name);
      domain
      |> Yojson.Basic.Util.member "commands"
      |> Yojson.Basic.Util.to_option Yojson.Basic.Util.to_list
      |> Option.map (List.map (get_command ~domain:name))
      |> Option.iter (fun b ->
             write_commands
               ("module " ^ name ^ " = struct " ^ String.concat "\n" b ^ " end")))
    domains

let info =
  let doc = "Parses CDP Protocols" in
  Cmd.info "CDP" ~doc
    ~exits:
      [
        Cmd.Exit.info 0 ~doc:"if all files were parsed successfully.";
        Cmd.Exit.info 1 ~doc:"on parsing errors.";
        Cmd.Exit.info 124 ~doc:"on command line parsing errors.";
        Cmd.Exit.info 125 ~doc:"on unexpected internal errors.";
      ]

let protocols =
  let doc = "A list protocols to parse." in
  let open Arg in
  non_empty
  & pos_left ~rev:true 0 non_dir_file []
  & info [] ~docv:"PROTOCOL(S)" ~doc

let output =
  let doc = "The direcory, where to put the generated api" in
  let open Arg in
  required & pos ~rev:true 0 (some dir) None & info [] ~docv:"DIR" ~doc

let cmd =
  let open Term in
  const main $ protocols $ output

let () = Cmd.v info cmd |> Cmd.eval |> exit
