let component = ReasonReact.statelessComponent("PostItem");

let make = (~post, _children) => {
  ...component,
  render: _self => {
    let title = ! post##isPublished ? post##title ++ "Draft" : post##title;
    <div>
      <Link className="no-underline ma1" href=("/detailpage/" ++ post##id)>
        <h2 className="f3 black-80 fw4 lh-solid"> (title |> Aliases.ste) </h2>
        /* (post##title |> Aliases.ste) */
        <p className="black-80 fw3"> (post##text |> Aliases.ste) </p>
      </Link>
    </div>;
  },
};