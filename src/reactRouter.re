module type RouteMatchParams = {type params;};

/**
 * This functor allows you to specify the types of the match params that
 * you expect in your React component.
 * Use this when you are sure that the React component rendered by a Route
 * receives the given params.
 *
 * Usage:
 *
module RouterMatch =
  SpecifyRouterMatch(
    {
      type params = {. "postId": string};
    }
  );

let make = (~match: RouterMatch.match, _children) => {...};
 */
module SpecifyRouterMatch = (Config: RouteMatchParams) => {
  type match = {. "params": Config.params};
};

type genericMatch = {. "params": Js.Dict.t(string)};

type renderFunc =
  {
    .
    /* Use name mangling notation prefix `_` to circumvent reserved names clashing.
       https://bucklescript.github.io/docs/en/object.html#invalid-field-names */
    "_match": genericMatch,
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

module Redirect = {
  [@bs.module "react-router-dom"]
  external reactClass : ReasonReact.reactClass = "Redirect";
  let make = (~_to: string, children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props={"to": _to}, children);
};

module NavLink = {
  [@bs.module "react-router-dom"]
  external navLink : ReasonReact.reactClass = "NavLink";
  let make = (~_to: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=navLink,
      ~props={"to": _to},
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