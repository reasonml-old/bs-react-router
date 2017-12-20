open ReactRouter;

module HomePage = {
    let component = ReasonReact.statelessComponent("HomePage");
    let make = (_children) => {
        ...component,
        render: (_self) => 
            <h1>{ReasonReact.stringToElement("Home page")}</h1>
    }
};

module UserPage = {
    let component = ReasonReact.statelessComponent("UserPage");
    let make = (_children) => {
        ...component,
        render: (_self) => 
            <h1>{ReasonReact.stringToElement("User page")}</h1>
    }
};

module App = {
    let component = ReasonReact.statelessComponent("App");
    let blueStyle = ReactDOMRe.Style.make(~color="#000099", ());

    let make = (_children) => {
        ...component,
        render: (_self) =>
            <div>
                <BrowserRouter>
                    <div>
                        <h1>{ReasonReact.stringToElement("Using NavLink")}</h1>
                        <NavLink _to="/">{ReasonReact.stringToElement("Home")}</NavLink>
                        <NavLink _to="/user" style=blueStyle>{ReasonReact.stringToElement("User")}</NavLink>

                        <h1>{ReasonReact.stringToElement("Using Link")}</h1>
                        <Link _to="/">{ReasonReact.stringToElement("Home")}</Link>
                        <Link _to="/user">{ReasonReact.stringToElement("User")}</Link>

                        <Switch>
                            /* Component as Prop can't trivially pass
                            so we pass a callback as a component to send the whole component */
                            <Route path="/" exact=true component=(() => <HomePage />) />
                            <Route path="/user" component=(() => <UserPage />) />
                        </Switch>
                    </div>
                </BrowserRouter>
            </div>
    };
};
