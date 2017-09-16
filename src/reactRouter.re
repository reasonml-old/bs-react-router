type renderFunc =
  Js.t {
    .
    _match : Js.Dict.t string, history : History.History.t, location : History.History.Location.t
  } =>
  ReasonReact.reactElement;

let optionToBool optional =>
  switch optional {
  | Some _ => true
  | _ => false
  };

module Route = {
  external route : ReasonReact.reactClass = "Route" [@@bs.module "react-router-dom"];
  let make
      exact::(exact: option bool)=?
      path::(path: option string)=?
      component::(component: option ('a => ReasonReact.reactElement))=?
      render::(render: option renderFunc)=?
      children =>
    ReasonReact.wrapJsForReason
      reactClass::route
      props::{
        "exact": Js.Boolean.to_js_boolean (optionToBool exact),
        "path": Js.Null_undefined.from_opt path,
        "component": Js.Null_undefined.from_opt component,
        "render": Js.Null_undefined.from_opt render
      }
      children;
};

module NavLink = {
  external navLink : ReasonReact.reactClass = "NavLink" [@@bs.module "react-router-dom"];
  let make _to::(_to: string) children =>
    ReasonReact.wrapJsForReason reactClass::navLink props::{"to": _to} children;
};

module BrowserRouter = {
  external browserRouter : ReasonReact.reactClass =
    "BrowserRouter" [@@bs.module "react-router-dom"];
  let make children =>
    ReasonReact.wrapJsForReason reactClass::browserRouter props::(Js.Obj.empty ()) children;
};

module ServerRouter = {
  external staticRouter : ReasonReact.reactClass = "StaticRouter" [@@bs.module "react-router"];
  let make context::(context: Js.Json.t) location::(location: Js.Json.t) children =>
    ReasonReact.wrapJsForReason
      reactClass::staticRouter props::{"context": context, "location": location} children;
};

let withROuter component => <Route render=component />;
