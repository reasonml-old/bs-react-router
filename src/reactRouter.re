type renderFunc = 
  {
    .
    "_match": Js.Dict.t(string),
    "history": History.History.t,
    "location": History.History.Location.t
  } =>
  ReasonReact.reactElement;

let optionToBool = (optional) => 
  switch optional {
  | Some _ => true
  | _ => false
  };

module Route = {
  [@bs.module "react-router-dom"] external route : ReasonReact.reactClass = "Route";
  let make =
      (
        ~exact: option(bool)=?,
        ~path: option(string)=?,
        ~component: option('a => ReasonReact.reactElement)=?,
        ~render: option(renderFunc)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=route,
      ~props={
        "exact": Js.Boolean.to_js_boolean(optionToBool(exact)),
        "path": Js.Null_undefined.from_opt(path),
        "component": Js.Null_undefined.from_opt(component),
        "render": Js.Null_undefined.from_opt(render)
      },
      children
    );
};

module NavLink = {
  [@bs.module "react-router-dom"] external navLink : ReasonReact.reactClass = "NavLink";
  let make = (~_to: string, children) =>
    ReasonReact.wrapJsForReason(~reactClass=navLink, ~props={"to": _to}, children);
};

module BrowserRouter = {
  [@bs.module "react-router-dom"]
  external browserRouter : ReasonReact.reactClass = "BrowserRouter";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=browserRouter, ~props=Js.Obj.empty(), children);
};

module ServerRouter = {
  [@bs.module "react-router"] external staticRouter : ReasonReact.reactClass = "StaticRouter";
  let make = (~context: Js.Json.t, ~location: Js.Json.t, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=staticRouter,
      ~props={"context": context, "location": location},
      children
    );
};

let withROuter = (component) => <Route render=component />;
