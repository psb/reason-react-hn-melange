# melange-opam-template (ReasonReact, Vite, Tailwind)

Forked from this [original template](https://github.com/melange-re/melange-opam-template) and changed to use Vite and Tailwind. This template uses only Reason syntax and not OCaml.

A simple project template using [Melange](https://github.com/melange-re/melange)
with [opam](https://opam.ocaml.org/).

If you are looking for a template with esy, check [melange-esy-template](https://github.com/melange-re/melange-esy-template).

## Quick Start

```shell
make init

# In separate terminals:
make watch
make vite
```

## React

React support is provided by [`reason-react`](https://github.com/reasonml/reason-react/). The entry point of the sample React app is [`src/Index.re`](src/Index.re).

### Fast refresh

To enable React fast refresh, write `.rei` interface files for each component.

## Commands

You can see all available commands by running `make help` or just `make`. Here
are a few of the most useful ones:

- `make init`: set up opam local switch and download OCaml, Melange and
  JavaScript dependencies
- `make install`: install OCaml, Melange and JavaScript dependencies
- `make watch`: watch for the filesystem and have Melange rebuild on every
  change
- `make dev`: serve the JS application with a local HTTP server
- `make preview`: build the JS and serve the built JS application with a local HTTP server

## JavaScript output

Since Melange just compiles source files into JavaScript files, it can be used
for projects on any JavaScript platform - not just the browser.

_This template includes just one `melange.emit` stanza and not the two stanzas from the original template. Please refer to the original template to see how to output JS code for the browser and node using two separate stanzas._

`_build/default/src/output/src/Index.js` in the `index.html` is used as the entry point for Vite.
