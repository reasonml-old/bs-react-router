external staticRouter : ReactRe.reactClass = "StaticRouter" [@@bs.module "react-router"];

module StaticRouter = {
  type location = Object Js.Json.t | String string;

  let createElement
    basename::(basename: string)
    context::(context: Js.Json.t)
    location::(location: location) =>
  ReactRe.wrapPropsShamelessly
    staticRouter
    {
      "basename": basename,
      "context": context,
      "location": location
    };
};
