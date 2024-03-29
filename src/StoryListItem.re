[@react.component]
let make = (~story: Story.Data.story, ~index: int) => {
  let renderIndex = () =>
    <aside className="mr-2">
      {React.string(string_of_int(index + 1) ++ ".")}
    </aside>;
  let renderTitle = () => {
    let content = React.string(story.title);
    <header className="text-lg font-semibold">
      {switch (story.url) {
       | Some(url) => <a href=url target="_blank"> content </a>
       | None =>
         <Link href={"/comments/" ++ string_of_int(story.id)}> content </Link>
       }}
    </header>;
  };
  let renderByline = () =>
    <div>
      <span>
        <b> {React.string(string_of_int(story.score))} </b>
        {React.string(" points")}
      </span>
      <span className="text-xs text-slate-400">
        {let time = story.time |> Utils.fromNow;
         let by = story.by;
         React.string({j| submitted $time by $by|j})}
      </span>
    </div>;
  /* TODO: badge */
  let renderArticleButton = () =>
    <div className="flex grow">
      {renderIndex()}
      <div> {renderTitle()} {renderByline()} </div>
    </div>;
  let renderCommentsButton = () =>
    <div className="flex w-24 justify-center">
      <Link href={"/comments/" ++ string_of_int(story.id)}>
        <div>
          <img
            alt="comments"
            className="mx-auto"
            width="40"
            src="comment.svg"
          />
        </div>
        <div className="text-xs">
          <span className="font-bold">
            {React.string(string_of_int(story.descendants))}
          </span>
          {React.string(" comments")}
        </div>
      </Link>
    </div>;

  <div className="flex flex-row py-2">
    {renderArticleButton()}
    {renderCommentsButton()}
  </div>;
};
