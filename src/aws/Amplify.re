
type t;
[@bs.module "@aws-amplify/core"] external amplify: t = "default";
[@bs.send] external configure: (t, AwsExports.t) => unit = "configure";
let configure = config => configure(amplify, config);

module Authenticator = {
  [@bs.module "aws-amplify-react-native"] [@react.component]
  external make:
    (~hideDefault: bool=?, ~onStateChange: 'a=?, ~theme:Js.t('a)=?,~children: React.element=?) =>
    React.element =
    "Authenticator";
};

module SignIn = {
  [@react.component] [@bs.module "aws-amplify-react-native/src/Auth/SignIn"]
  external make: _ => React.element = "SignIn";
};