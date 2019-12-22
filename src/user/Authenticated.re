open UserTypes;
open ReactNative;
module Authenticator = {
  open WithAuthenticator;
  let makeProps = AppNavigator.makeProps;
  let make =
    withAuthenticator(AppNavigator.make, ~theme=AmplifyTheme.theme, ());
};
[@react.component]
let make = (~children: React.element) => {
  let (user, dispatchUserAction) = UserContext.useUser();
  <>
    {switch (user) {
     | Guest => <Authenticator />
     | Authenticated => children
     }}
  </>;
};

let default = make;
