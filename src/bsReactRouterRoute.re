external route : ReactRe.reactClass = "Route" [@@bs.module "react-router-dom"];

let make
    exact::(exact: bool)
    path::(path: string)
    component::(
      component:
        Js.t {
          .
          match : BsReactRouter.Utils.match,
          history : BsReactRouter.Utils.history,
          location : BsReactRouter.Utils.location
        } =>
        ReasonReact.reactElement
    )
    children =>
  ReasonReact.wrapJsForReason
    reactClass::route
    props::{"exact": Js.Boolean.to_js_boolean exact, "path": path, "component": component}
    children;
