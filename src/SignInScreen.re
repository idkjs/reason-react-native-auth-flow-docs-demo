open ReactNative;
open ReactNavigation;
open GlobalStyle;

[@react.component]
let make = (~navigation: Navigation.t) => {
  <View style=styles##container> <Amplify.SignIn /> </View>;
};