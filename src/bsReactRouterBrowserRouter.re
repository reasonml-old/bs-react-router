external confirm : string => Js.boolean = "" [@@bs.val];

external browserRouter : ReactRe.reactClass = "BrowserRouter" [@@bs.module "react-router-dom"];

let make
    basename::(basename: string)="/"
    forceRefresh::(forceRefresh: bool)=false
    getUserConfirmation::(getUserConfirmation: string => Js.boolean)=confirm
    keyLength::(keyLength: int)=6
    children =>
  ReasonReact.wrapJsForReason
    reactClass::browserRouter
    props::{
      "basename": basename,
      "forceRefresh": Js.Boolean.to_js_boolean forceRefresh,
      "getUserConfirmation": getUserConfirmation,
      "keyLength": keyLength
    }
    children;
