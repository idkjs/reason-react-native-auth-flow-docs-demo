open GlobalStyle;
open ReactNative;
open ReactNavigation;

[@react.component]
let make = (~navigation: Navigation.t) => {
  let _showMoreApp = () => navigation->Navigation.navigate("Other");

  <View style=styles##container>
    <Button title="Show me more of the app" onPress={_ => _showMoreApp()} />
    <Button
      title="Actually, sign me out :)"
      onPress={_ => Utils.signOutAsync(~navigation)}
    />
  </View>;
};
