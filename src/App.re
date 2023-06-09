// This sample forces an import of Belt.*, so that CI builds can ensure that
// Melange has been installed correctly for JS bundlers to be able to find it.
[@react.component]
let make = () => {
  let (count, setCount) = React.useState(() => 0);

  <div>
    <Heading count />
    <button
      className="bg-blue-600 text-neutral-100 text-lg px-4 mt-4"
      onClick={_ => setCount(_ => count + 1)}>
      {React.string("Click me")}
    </button>
  </div>;
};
