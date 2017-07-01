external navLink : ReactRe.reactClass = "NavLink" [@@bs.module "react-router-dom"];

/* TODO */
/* isActive: func */
/* location: object */

let make
    activeClassName::(activeClassName: string)="class"
    activeStyle::(activeStyle: ReactDOMRe.Style.t)=(ReactDOMRe.Style.make ())
    exact::(exact: bool)=false
    strict::(strict: bool)=false
    _to::(_to: Link._to 'a)
    replace::(replace: bool)=false
    children =>
  ReasonReact.wrapJsForReason
    reactClass::navLink
    props::{
      "activeClassName": activeClassName,
      "activeStyle": activeStyle,
      "exact": exact,
      "strict": strict,
      "to": Link.evalTo _to,
      "replace": Js.Boolean.to_js_boolean replace
    }
    children;
