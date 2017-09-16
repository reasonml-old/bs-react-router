type routerProps =
  Js.t {
    .
    _match : Js.t {. params : Js.Dict.t string, path : string, url : string, isExact : bool},
    history : PrivateHistory.History.t,
    location : PrivateHistory.History.Location.t
  };

type renderFunc = routerProps => ReasonReact.reactElement;

module BrowserRouter = {
  external browserRouter : ReasonReact.reactClass =
    "BrowserRouter" [@@bs.module "react-router-dom"];
  let make children =>
    ReasonReact.wrapJsForReason reactClass::browserRouter props::(Js.Obj.empty ()) children;
};

let optionToBool optional =>
  switch optional {
  | Some _ => true
  | _ => false
  };

module Route = {
  external route : ReasonReact.reactClass = "Route" [@@bs.module "react-router-dom"];
  let make
      exact::(exact: option bool)=?
      strict::(strict: option bool)=?
      path::(path: option string)=?
      component::(component: option ('a => ReasonReact.reactElement))=?
      render::(render: option renderFunc)=?
      children =>
    ReasonReact.wrapJsForReason
      reactClass::route
      props::{
        "exact": Js.Boolean.to_js_boolean (optionToBool exact),
        "strict": Js.Boolean.to_js_boolean (optionToBool strict),
        "path": Js.Null_undefined.from_opt path,
        "component": Js.Null_undefined.from_opt component,
        "render": Js.Null_undefined.from_opt render
      }
      children;
};

module Link = {
  external navLink : ReasonReact.reactClass = "Link" [@@bs.module "react-router-dom"];
  let make _to::(_to: string) replace::(replace: option bool)=? children =>
    ReasonReact.wrapJsForReason
      reactClass::navLink
      props::{"to": _to, "replace": Js.Null_undefined.from_opt replace}
      children;
};

module NavLink = {
  external navLink : ReasonReact.reactClass = "NavLink" [@@bs.module "react-router-dom"];
  let make
      _to::(_to: string)
      replace::(replace: option bool)=?
      activeClassName::(activeClassName: option string)=?
      exact::(exact: option bool)=?
      strict::(strict: option bool)=?
      children =>
    ReasonReact.wrapJsForReason
      reactClass::navLink
      props::{
        "to": _to,
        "replace": Js.Null_undefined.from_opt replace,
        "activeClassName": Js.Null_undefined.from_opt activeClassName,
        "exact": Js.Boolean.to_js_boolean (optionToBool exact),
        "strict": Js.Boolean.to_js_boolean (optionToBool strict)
      }
      children;
};

let withROuter component => <Route render=component />;
