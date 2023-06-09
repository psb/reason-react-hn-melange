type root;

[@bs.module "react-dom/client"]
external createRoot: Dom.element => root = "createRoot";

[@bs.send] external render: (root, React.element) => unit = "render";

ReactDOM.querySelector("#root")
->(
    fun
    // | Some(root) => ReactDOM.render(<App />, root)
    | Some(root) => {
        let rootNode = createRoot(root);
        render(rootNode, <App />);
      }

    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
