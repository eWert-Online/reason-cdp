(lang dune 2.8)

(generate_opam_files true)

(name "cdp")

(source
 (github eWert-Online/reason-cdp))

(license MIT)

(authors "Torben Ewert")

(package
 (name "cdp")
 (synopsis "Chrome DevTools Protocol types")
 (depends
  cmdliner
  dune
  fileutils
  ppx_yojson_conv
  (reason
   (and
    (>= 3.6.0)
    (< 4.0.0)))
  (ocaml
   (and
    (>= 4.10.0)
    (< 5.0.0)))
  yojson))
