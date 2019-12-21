open ReactNavigation;
// the code we want to emulate from js demo
// const AppStack = createStackNavigator({ Home: HomeScreen, Other: OtherScreen });
// const AuthStack = createStackNavigator({ SignIn: SignInScreen });
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
