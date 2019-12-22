type signUpConfig = Js.Nullable.t({.});
type withAuthenticator = {
  [@bs.as "Comp"]
  comp: React.element,
  includeGreetings: bool,
  federated: Js.Nullable.t({.}),
  theme: option(ReactNative.Style.t),
  signUpConfig,
};
type defaultChildren = array(React.element);

module Loading = {
  [@react.component] [@bs.module "aws-amplify-react-native/src/Auth/Loading"]
  external make: _ => React.element = "Loading";
};
module SignIn = {
  [@react.component] [@bs.module "aws-amplify-react-native/src/Auth/SignIn"]
  external make: _ => React.element = "SignIn";
};
module SignUp = {
  [@react.component] [@bs.module "aws-amplify-react-native/src/Auth/SignUp"]
  external make: signUpConfig => React.element = "SignUp";
};
module ConfirmSignIn = {
  [@react.component]
  [@bs.module "aws-amplify-react-native/src/Auth/ConfirmSignIn"]
  external make: _ => React.element = "ConfirmSignIn";
};
module ConfirmSignUp = {
  [@react.component]
  [@bs.module "aws-amplify-react-native/src/Auth/ConfirmSignUp"]
  external make: _ => React.element = "ConfirmSignUp";
};
module ForgotPassword = {
  [@react.component]
  [@bs.module "aws-amplify-react-native/src/Auth/ForgotPassword"]
  external make: _ => React.element = "ForgotPassword";
};
module RequireNewPassword = {
  [@react.component]
  [@bs.module "aws-amplify-react-native/src/Auth/RequireNewPassword"]
  external make: _ => React.element = "RequireNewPassword";
};
module Greetings = {
  [@react.component] [@bs.module "aws-amplify-react-native/src/Auth/Greetings"]
  external make: _ => React.element = "Greetings";
};
module VerifyContact = {
  [@react.component]
  [@bs.module "aws-amplify-react-native/src/Auth/VerifyContact"]
  external make: _ => React.element = "VerifyContact";
};

let defaultChildren: defaultChildren = [|
  <VerifyContact />,
  <Greetings />,
  <ConfirmSignUp />,
  <ForgotPassword />,
  <RequireNewPassword />,
  <ConfirmSignIn />,
  <SignUp />,
  <SignIn />,
  <Loading />,
|];
// type authStateOptions = [ |`signedOut |`signedIn| `mfaRequired| `newPasswordRequired|`loading ];
type authState = [
  | `signedOut
  | `signedIn
  | `mfaRequired
  | `newPasswordRequired
  | `loading
];
type authData = Js.Nullable.t({.});
type onStateChange = (authState, authData) => unit;
let useIsMounted = () => {
  let ref = React.useRef(false);

  React.useEffect0(() => {
    ref->React.Ref.setCurrent(true);
    Some(() => ref->React.Ref.setCurrent(false));
  });
  ref;
};
module Authenticator = {
  type state = {
    authState,
    authData,
    error: Js.Nullable.t({.}),
  };
  let initialState = {
    authState: `loading,
    authData: Js.Nullable.null,
    error: Js.Nullable.null,
  };
  [@react.component]
  let make = (~onStateChange: option(onStateChange), ~children, ()) => {
    let (state, setState) = React.useState(() => initialState);
    /* Obj.magic because this returns:
           React.Ref.t(bool)
       type t('value)
       <root>/src/AuthScreen.re

       Error: This expression has type React.Ref.t(bool)
              but an expression was expected of type bool
             */
    let isMounted = useIsMounted()->Obj.magic;
    let handleStateChange = state => {
      let {authState, authData} = state;
      // logger.debug('authenticator state change ' + state);
      if (!isMounted) {
        ();
      };
      if (authState === authState) {
        ();
      };

      let authState =
        switch (authState) {
        | `signedOut => `signedIn
        | _ => authState
        };
      setState(_ => {authState, authData, error: Js.Nullable.null});
      switch (onStateChange) {
      | Some(onStateChange) => onStateChange(authState, authData)
      | None => ()
      };
    };
    children;
  };
};