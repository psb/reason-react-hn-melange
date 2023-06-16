open Belt;

type action =
  | Toggle(option(string));

type state = {collapsed_comments: Set.Int.t};
let initialState = {collapsed_comments: Set.Int.empty};

let toggleComment = (collapsed, idMaybe: option(string)) =>
  switch (idMaybe) {
  | Some(idString) =>
    let id = int_of_string(idString);
    if (Set.Int.has(collapsed, id)) {
      Set.Int.remove(collapsed, id);
    } else {
      Set.Int.add(collapsed, id);
    };
  | None => collapsed
  };
[@react.component]
let make = (~story: Story.Data.story_with_comments) => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Toggle(commentId) => {
            collapsed_comments:
              toggleComment(state.collapsed_comments, commentId),
          }
        },
      initialState,
    );

  let getCommentIdFromEvent = (event: ReactEvent.Mouse.t) =>
    Utils.getAttribute(ReactEvent.Mouse.currentTarget(event), "name");

  let renderCommentText = (textMaybe: option(string)) =>
    switch (textMaybe) {
    | Some(text) =>
      <div dangerouslySetInnerHTML={Utils.dangerousHtml(text)} />
    | None => React.string("missing comment")
    };

  let rec renderCommentKids = (comment: Story.Data.comment_present) =>
    renderCommentList(comment.kids)
  and renderComment = (id: int) => {
    let commentMaybe = Map.Int.get(story.comments, id);
    <div key={string_of_int(id)}>
      {switch (commentMaybe) {
       | Some(commentPresentOrDeleted) =>
         switch (commentPresentOrDeleted) {
         | Story.Data.CommentPresent(comment) =>
           let openComment =
             !Set.Int.has(state.collapsed_comments, comment.id);
           <div>
             <div
               className="flex pt-2 text-slate-400"
               name={string_of_int(comment.id)}
               onClick={event =>
                 dispatch(Toggle(getCommentIdFromEvent(event)))
               }>
               <img
                 alt={openComment ? "hide" : "show"}
                 src={openComment ? "/chevron-down.svg" : "/chevron-right.svg"}
                 width="20"
               />
               <span className="ml-1 text-sm">
                 {let time = Utils.fromNow(comment.time);
                  let by = comment.by;
                  React.string({j| $time by $by|j})}
               </span>
             </div>
             {if (openComment) {
                <div className="pl-4 text-sm">
                  {renderCommentText(comment.text)}
                  {renderCommentKids(comment)}
                </div>;
              } else {
                <noscript />;
              }}
           </div>;
         | Story.Data.CommentDeleted(_) =>
           <div className="text-red-400">
             {React.string(
                "[comment deleted (id=" ++ string_of_int(id) ++ ")]",
              )}
           </div>
         }
       | None =>
         <div className="text-red-400">
           {React.string(
              "[comment not loaded (id=" ++ string_of_int(id) ++ ")]",
            )}
         </div>
       }}
    </div>;
  }
  and renderCommentList = (commentIds: option(array(int))) =>
    switch (commentIds) {
    | Some(ids) =>
      let commentList = Array.map(ids, id => renderComment(id));
      <div> {React.array(commentList)} </div>;
    | None => <div />
    };
  renderCommentList(story.kids);
};
