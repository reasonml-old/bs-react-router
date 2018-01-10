type match = {. "params": Js.Dict.t(string)};

type renderFunc =
  {
    .
    /* Use name mangling notation prefix `_` to circumvent reserved names clashing.
       https://bucklescript.github.io/docs/en/object.html#invalid-field-names */
    "_match": match,
    "history": History.History.t,
    "location": History.History.Location.t
  } =>
  ReasonReact.reactElement;

let optionToBool = optional =>
  switch optional {
  | Some(_) => true
  | _ => false
  };

module Route = {
  [@bs.module "react-router-dom"]
  external route : ReasonReact.reactClass = "Route";
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

module Switch = {
  [@bs.module "react-router-dom"] external reactClass : ReasonReact.reactClass = "Switch";
  let make = (children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=Js.Obj.empty(),
      children
    );
};

module Link = {
  [@bs.module "react-router-dom"] external link : ReasonReact.reactClass = "Link";
  let make =
      (
        ~to_: string,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=link,
      ~props={
        "to": to_
      },
      children
    );
};

module Redirect = {
  [@bs.module "react-router-dom"]
  external reactClass : ReasonReact.reactClass = "Redirect";
  let make = (~_to: string, children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props={"to": _to}, children);
};

module NavLink = {
  [@bs.module "react-router-dom"]
  external navLink : ReasonReact.reactClass = "NavLink";
  let make = 
    (
      ~_to: string,
      ~activeClassName: option(string)=?,
      ~style: option(ReactDOMRe.style)=?,
      ~activeStyle: option(ReactDOMRe.style)=?,
      children
    ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=navLink,
      ~props={
        "to": to_,
        "activeClassName": Js.Null_undefined.from_opt(activeClassName),
        "style": Js.Null_undefined.from_opt(style),
        "activeStyle": Js.Null_undefined.from_opt(activeStyle)
      },
      children
    );
};

module BrowserRouter = {
  [@bs.module "react-router-dom"]
  external browserRouter : ReasonReact.reactClass = "BrowserRouter";
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=browserRouter,
      ~props=Js.Obj.empty(),
      children
    );
};

module ServerRouter = {
  [@bs.module "react-router"]
  external staticRouter : ReasonReact.reactClass = "StaticRouter";
  let make = (~context: Js.Json.t, ~location: Js.Json.t, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=staticRouter,
      ~props={"context": context, "location": location},
      children
    );
};
