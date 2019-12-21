open ReactNative;
open ReactNavigation;
open GlobalStyle;

[@react.component]
let make = (~navigation: Navigation.t) => {
  <View style=styles##container>
    <Button title="Sign in!" onPress={_ => Utils.signInAsync(~navigation)} />
  </View>;
};
