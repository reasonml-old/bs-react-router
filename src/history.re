module History = {
  type t;
  module Location = {
    type t;
    [@bs.get] external pathname : t => string = "";
    [@bs.get] external search : t => string = "";
    [@bs.get] external hash : t => string = "";
    [@bs.get] [@bs.return null_undefined_to_opt] external key : t => option(string) = "";
  };
  type action = [ | `PUSH | `REPLACE | `POP]; /*  [@@bs.string] */
  [@bs.get] external length : t => int = "";
  [@bs.get] external action : t => action = "";
  [@bs.get] external location : t => string = "";
  [@bs.send]
  external listen : (t, [@bs.uncurry] ((~location: Location.t, ~action: action) => unit)) => unit =
    ""; /* TODO: state typing */
  module State = {
    type t;
  };
  [@bs.send] external push : (t, ~url: string, ~state: list(State.t)) => unit = "";
  [@bs.send] external replace : (t, ~url: string, ~state: list(State.t)) => unit = "";
  [@bs.send] external go : (t, ~jumps: int) => unit = "";
  [@bs.send] external goBack : t => unit = "";
  [@bs.send] external goForward : t => unit = "";
};

type getUserConfirmation = (~path: string, ~confirmation: bool) => unit;

type browserHistoryOpt = {
  basename: string,
  forceRefresh: bool,
  keyLength: int,
  getUserConfirmation
};

[@bs.module "history"]
external createBrowserHistory : browserHistoryOpt => History.t = "createBrowserHistory";

type memoryHistoryOpt = {
  initialEntries: list(string),
  initialIndex: int,
  keyLength: int
};

[@bs.module] external createMemoryHistory : memoryHistoryOpt => History.t = "";

type hashHistoryOpt = {
  basename: string,
  hashType: string,
  getUserConfirmation
};

[@bs.module] external createHashHistory : hashHistoryOpt => History.t = "";