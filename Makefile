.PHONY: all build generate install update fmt clean clear
.SILENT: all build generate install update fmt clean clear

all: build

build:
	dune build -p cdp-generator

test:
	dune build -p cdp

generate:
	dune exec -- cdp ./devtools-protocol/json/browser_protocol.json ./devtools-protocol/json/js_protocol.json ./lib
	ocamlformat --inplace ./lib/*.ml

install:
	if ! [ -e _opam ]; then \
		opam switch create . --empty ; \
	fi
	opam install ./*.opam --locked --deps-only --with-test --with-doc --yes
	opam lock .
	opam install -y ocaml-lsp-server

update:
	opam update
	opam upgrade
	opam lock .

fmt:
	dune build @fmt --auto-promote --silent

clean:
	rm -rf _build

clear: clean
	rm -rf _opam
