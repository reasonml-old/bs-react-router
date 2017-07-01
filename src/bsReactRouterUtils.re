type location = Js.t {
  .
  key: Js.Option.t string,
  pathname: string,
  search: Js.Option.t string,
  hash: Js.Option.t string,
  state: Js.Json.t
};

type history = Js.t {
  .
  length: int,
  action: string,
  location: location,
  push: string => Js.Json.t => unit,
  replace: string => Js.Json.t => unit,
  go: int => unit,
  goBack: unit => unit,
  goForward: unit => unit,
  block: string => (unit => unit) /* TODO GADT the more complex block case */
};

type match = Js.t {
  .
  params: Js.Json.t,
  isExact: Js.boolean,
  path: string,
  url: string
};

type matchProps = Js.t {
  .
  path: string,
  strict: Js.boolean,
  exact: Js.boolean
};

external matchPath: string => matchProps => match = "matchPath" [@@bs.module "react-router-dom"];
/* TODO external withRouter: ReasonReact.reactClass => ReasonReact.reactClass = "withRouter" [@@bs.module "react-router-dom"]; */
