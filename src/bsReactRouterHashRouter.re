external confirm : string => Js.boolean = "" [@@bs.val];

external hashRouter : ReactRe.reactClass = "HashRouter" [@@bs.module "react-router-dom"];

type hash = Slash | NoSlash | HashBang;

let hashToString hash => switch hash {
| Slash => "slash"
| NoSlash => "noslash"
| HashBang => "hashbang"
};

let make
    basename::(basename: string)="/"
    getUserConfirmation::(getUserConfirmation: string => Js.boolean)=confirm
    hashType::(hashType: hash)=Slash
    children =>
  ReasonReact.wrapJsForReason
    reactClass::hashRouter
    props::{
      "basename": basename,
      "getUserConfirmation": getUserConfirmation,
      "hashType": hashToString hashType
    }
    children;
