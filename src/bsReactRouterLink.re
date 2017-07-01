external link : ReactRe.reactClass = "Link" [@@bs.module "react-router-dom"];

type toObj = {
  pathname: string,
  search: string,
  hash: string,
  state: Js.Json.t
};

type _to 'a =
  | String string : _to string
  | Obj toObj : _to toObj;

let evalTo: type a. _to a => a = fun t => switch t {
| String a => a
| Obj a => a
};

let make
    _to::(_to: _to 'a)
    replace::(replace: bool)=false
    children =>
  ReasonReact.wrapJsForReason
    reactClass::link
    props::{
      "to": evalTo _to,
      "replace": Js.Boolean.to_js_boolean replace
    }
    children;
