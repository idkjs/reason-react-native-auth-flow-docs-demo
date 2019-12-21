open GlobalStyle;
open ReactNative;
open ReactNavigation;

[@react.component]
let make = (~navigation: Navigation.t) => {
  <View style=styles##container>
    <Button
      title="I'm done, sign me out"
      onPress={_ => Utils.signOutAsync(~navigation)}
    />
    <StatusBar barStyle=`default />
  </View>;
};
