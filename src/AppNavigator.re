open ReactNative;
open ReactNavigation;
open GlobalStyle;
module SignInScreen = {
  [@react.component]
  let make = (~navigation: Navigation.t) => {
    let _signInAsync = () => {
      Js.Promise.
        (
          AsyncStorage.setItem("userToken", "abc")
          |> then_(_result =>
               resolve(navigation->Navigation.navigate("App"))
             )
        );
    };
    <View style=styles##container>
      <Button title="Sign in!" onPress={_ => _signInAsync() |> ignore} />
    </View>;
  };
  make->NavigationOptions.setNavigationOptions(
    NavigationOptions.t(~title="Please sign in", ()),
  );
};

module HomeScreen = {
  [@react.component]
  let make = (~navigation: Navigation.t) => {
    let _showMoreApp = () => navigation->Navigation.navigate("Other");
    let _signOutAsync = () => {
      AsyncStorage.clear() |> ignore;
      navigation->Navigation.navigate("Auth");
    };

    <View style=styles##container>
      <Button title="Show me more of the app" onPress={_ => _showMoreApp()} />
      <Button
        title="Actually, sign me out :)"
        onPress={_ => _signOutAsync()}
      />
    </View>;
  };
  make->NavigationOptions.setNavigationOptions(
    NavigationOptions.t(~title="Welcome to the app!", ()),
  );
};

module OtherScreen = {
  [@react.component]
  let make = (~navigation: Navigation.t) => {
    let _signOutAsync = () => {
      AsyncStorage.clear() |> ignore;
      navigation->Navigation.navigate("Auth");
    };

    <View style=styles##container>
      <Button title="I'm done, sign me out" onPress={_ => _signOutAsync()} />
      <StatusBar barStyle=`default />
    </View>;
  };
  make->NavigationOptions.setNavigationOptions(
    NavigationOptions.t(~title="Lots of features here", ()),
  );
};

module AuthLoadingScreen = {
  [@react.component]
  let make = (~navigation: Navigation.t) => {
    // Fetch the token from storage then navigate to our appropriate place
    let _bootstrapAsync = () => {
      AsyncStorage.getItem("userToken")
      |> Js.Promise.then_(stringOrNull => {
           // This will switch to the App screen or Auth screen and this loading screen will be unmounted and thrown away.

           Js.log2("CHECKING_AUTH_TOKEN", stringOrNull);
           switch (Js.Null.toOption(stringOrNull)) {
           | None =>
             Js.Promise.resolve(navigation->Navigation.navigate("Auth"))
           | Some(_stringOrNull) =>
             Js.Promise.resolve(navigation->Navigation.navigate("App"))
           };
         });
    };
    React.useEffect(() => {
      _bootstrapAsync() |> ignore;
      None;
    });
    <View style=styles##container>
      <ActivityIndicator />
      <StatusBar barStyle=`default />
    </View>;
  };
};

module AppStack = {
  let routes = {"Home": HomeScreen.make, "Other": OtherScreen.make};

  let navigator =
    StackNavigator.(
      makeWithConfig(routes, config(~mode=`modal, ~headerMode=`none, ()))
    );

  navigator->NavigationOptions.setNavigationOptions(
    NavigationOptions.t(~tabBarVisible=false, ()),
  );
};

module AuthStack = {
  let routes = {"SignIn": SignInScreen.make};

  let navigator =
    StackNavigator.(
      makeWithConfig(routes, config(~mode=`modal, ~headerMode=`none, ()))
    );

  navigator->NavigationOptions.setNavigationOptions(
    NavigationOptions.t(~tabBarVisible=false, ()),
  );
};
module AuthFlowAppContainer =
  AppContainer.Make({
    type screenProps = {. "someProp": int};

    let navigator =
      SwitchNavigator.makeWithConfig(
        {
          "App": AppStack.navigator,
          "Auth": AuthStack.navigator,
          "AuthLoading": AuthLoadingScreen.make,
        },
        SwitchNavigator.config(~initialRouteName="AuthLoading", ()),
      );
  });
[@react.component]
let make = () => {
  let screenProps = {"someProp": 42};
  <AuthFlowAppContainer screenProps />;
};