[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | [] => <TopStories />
  | ["comments", id] => <CommentsPage id={int_of_string(id)} />
  | _ => <NotFound />
  };
};
