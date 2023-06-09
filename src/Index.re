ReactDOM.querySelector("#root")
->(
    fun
    | Some(root) => ReactDOM.render(<App text=World.text />, root)
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
