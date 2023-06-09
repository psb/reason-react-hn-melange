[@react.component]
let make = () =>
  <div className="flex flex-col mt-8">
    <img alt="Page not found" src="/notfound404.png" />
    <p className="text-center text-xl mt-4">
      {React.string("The page you're looking for can't be found. Go home by ")}
      <Link href="/" className="underline">
        {React.string("clicking here!")}
      </Link>
    </p>
  </div>;
