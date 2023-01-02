(lang dune 2.8)

(generate_opam_files true)

(name "cdp")

(source
 (github eWert-Online/reason-cdp))

(license MIT)

(authors "Torben Ewert <torben@ewert-online.com>")

(maintainers "Torben Ewert <torben@ewert-online.com>")

(package
 (name "cdp")
 (synopsis "Chrome DevTools Protocol types")
 (depends dune ppx_yojson_conv ocaml yojson))

(package
 (name "cdp-generator")
 (synopsis "Chrome DevTools Protocol types generator")
 (depends cmdliner dune fileutils ocamlformat ocaml yojson))
