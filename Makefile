.PHONY: all build generate install update fmt clean clear
.SILENT: all build generate install update fmt clean clear

all: build

build:
	opam exec -- dune build -p cdp-generator

test:
	opam exec -- dune build -p cdp

generate:
  # rm -rf ./devtools-protocol
  # git clone --depth=1 https://github.com/ChromeDevTools/devtools-protocol.git ./devtools-protocol
	opam exec -- dune exec -- cdp ./devtools-protocol/json/browser_protocol.json ./devtools-protocol/json/js_protocol.json ./lib
	opam exec -- ocamlformat --inplace ./lib/*.ml

install:
	if ! [ -e _opam ]; then \
		opam switch create . --empty ; \
	fi
	opam install ./*.opam --deps-only --with-test --with-doc --yes
	opam install -y ocaml-lsp-server

update:
	opam update
	opam upgrade

fmt:
	opam exec -- dune build @fmt --auto-promote --silent

clean:
	rm -rf _build

clear: clean
	rm -rf _opam
