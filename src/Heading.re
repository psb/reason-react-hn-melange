[@react.component]
let make = (~count: int) => {
  <p className="bg-slate-300 text-6xl p-4">
    {React.string(
       Texts.Heading_texts.text1
       ++ Belt.Int.toString(count)
       ++ Texts.Heading_texts.text2,
     )}
  </p>;
};
