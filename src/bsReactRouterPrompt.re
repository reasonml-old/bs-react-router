external prompt : ReactRe.reactClass = "Prompt" [@@bs.module "react-router-dom"];

type message 'a =
  | String string: message string
  | Func (BsReactRouter.Utils.location => string => string): message (BsReactRouter.Utils.location => string => string); /* TODO handle case where return true */

let make
    message::(message: message 'a)
    when::(_when: bool)=false
    children =>
  ReasonReact.wrapJsForReason
    reactClass::prompt
    props::{
      "message": message,
      "when": Js.Boolean.to_js_boolean _when
    }
    children;
