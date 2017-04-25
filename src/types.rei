type match = Js.t {
  .
  params: Js.Json.t,
  isExact: Js.boolean,
  path: string,
  url: string
};

type location = Js.t {
  .
  key: string,
  pathname: string,
  search: string,
  hash: string
};

type history = Js.t {
  .
  length: int,
  location: string,
  action: string
};
