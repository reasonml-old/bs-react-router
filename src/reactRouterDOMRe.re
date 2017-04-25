external navLink : ReactRe.reactClass = "NavLink" [@@bs.module "react-router-dom"];
external route : ReactRe.reactClass = "Route" [@@bs.module "react-router-dom"];
external browserRouter : ReactRe.reactClass = "BrowserRouter" [@@bs.module "react-router-dom"];

let fromOption = fun default option => {
  switch option {
  | Some x => x
  | None => default
  };
};

module BrowserRouter = {
/* getUserConfirmation: func */
  type location = Object Js.Json.t | String string;

  let createElement
    keyLength::(keyLength: option int)=?
    forceRefresh::(forceRefresh: bool)
    basename::(basename: string)
    context::(context: Js.Json.t)
    location::(location: location) =>
  ReactRe.wrapPropsShamelessly
    browserRouter
    {
      "keyLength": fromOption 0 keyLength,
      "forceRefresh": Js.Boolean.to_js_boolean forceRefresh,
      "basename": basename,
      "context": context,
      "location": location
    };
};

module Route = {
  type routeParams = Js.t {
    .
    _match: Types.match,
    location: Types.location,
    history: Types.history
  };

  let createElement
    exact::(exact: option bool)
    path::(path: option string)
    component::(component: option ReactRe.reactClass)
    render::(render: option (routeParams => ReactRe.reactElement)) =>
  ReactRe.wrapPropsShamelessly
    route
    {
      "exact": Js.Boolean.to_js_boolean (fromOption false exact),
      "path": Js.Null_undefined.from_opt path,
      "component": Js.Null_undefined.from_opt component,
      "render": Js.Null_undefined.from_opt render,
    };
};

module NavLink = {
  let createElement _to::(_to: string) =>
  ReactRe.wrapPropsShamelessly
    navLink
    {
      "to": _to
    };
};
