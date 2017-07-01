external redirect : ReactRe.reactClass = "Redirect" [@@bs.module "react-router-dom"];


let make
    to::(_to: BsReactRouter.Link._to 'a)
    push::(push: bool)=false
    from::(from: option string)
    children =>
  ReasonReact.wrapJsForReason
    reactClass::redirect
    props::{
      "to": _to,
      "push": Js.Boolean.to_js_boolean push,
      "from": Js.Null_undefined.from_opt from,
    }
    children;

