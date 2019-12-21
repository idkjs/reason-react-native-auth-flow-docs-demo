// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as React from "react";
import * as HomeScreen from "./HomeScreen.bs.js";
import * as OtherScreen from "./OtherScreen.bs.js";
import * as SignInScreen from "./SignInScreen.bs.js";
import * as ReactNavigation from "react-navigation";
import * as AuthLoadingScreen from "./AuthLoadingScreen.bs.js";
import * as ReactNavigationStack from "react-navigation-stack";
import * as AppContainer$ReactNavigation from "reason-react-navigation/src/AppContainer.bs.js";

var routes = {
  Home: HomeScreen.make,
  Other: OtherScreen.make
};

var $$navigator = ReactNavigationStack.createStackNavigator(routes, {
      mode: "modal",
      headerMode: "none"
    });

$$navigator.navigationOptions = {
  tabBarVisible: false
};

var AppStack = {
  routes: routes,
  $$navigator: $$navigator
};

var routes$1 = {
  SignIn: SignInScreen.make
};

var $$navigator$1 = ReactNavigationStack.createStackNavigator(routes$1, {
      mode: "modal",
      headerMode: "none"
    });

$$navigator$1.navigationOptions = {
  tabBarVisible: false
};

var AuthStack = {
  routes: routes$1,
  $$navigator: $$navigator$1
};

var $$navigator$2 = ReactNavigation.createSwitchNavigator({
      App: $$navigator,
      Auth: $$navigator$1,
      AuthLoading: AuthLoadingScreen.make
    }, {
      initialRouteName: "AuthLoading"
    });

var AuthFlowAppContainer = AppContainer$ReactNavigation.Make({
      $$navigator: $$navigator$2
    });

function AppNavigator(Props) {
  var screenProps = {
    someProp: 42
  };
  return React.createElement(AuthFlowAppContainer.make, {
              screenProps: screenProps
            });
}

var make = AppNavigator;

var $$default = AppNavigator;

export {
  AppStack ,
  AuthStack ,
  AuthFlowAppContainer ,
  make ,
  $$default ,
  $$default as default,
  
}
/* navigator Not a pure module */