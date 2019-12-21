// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as API from "./aws/API.bs.js";
import * as Expo from "expo";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Theme from "./Theme.bs.js";
import * as React from "react";
import * as Amplify from "./aws/Amplify.bs.js";
import * as Font$Expo from "reason-expo/src/Font.bs.js";
import * as AwsExports from "./aws/AwsExports.bs.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as AmplifyTheme from "./aws/AmplifyTheme.bs.js";
import * as AppNavigator from "./AppNavigator.bs.js";
import * as ReactNative from "react-native";
import * as AwsAmplifyReactNative from "aws-amplify-react-native";

Amplify.configure(AwsExports.config);

API.configure(AwsExports.config);

function makeProps(prim, prim$1) {
  var tmp = { };
  if (prim !== undefined) {
    tmp.key = Caml_option.valFromOption(prim);
  }
  return tmp;
}

var make = AwsAmplifyReactNative.withAuthenticator(AppNavigator.make, AmplifyTheme.theme);

var Authenticator = {
  makeProps: makeProps,
  make: make
};

var styles = ReactNative.StyleSheet.create({
      container: {
        backgroundColor: Theme.Colors.primaryLight,
        flex: 1
      }
    });

ReactNative.YellowBox.ignoreWarnings(/* array */[
      "Possible Unhandled Promise Rejection",
      "Remote debugger",
      "UIManager['getConstants']"
    ]);

Amplify.configure(AwsExports.config);

API.configure(AwsExports.config);

function loadResourcesAsync(param) {
  return Font$Expo.loadAsync(/* :: */[
              /* tuple */[
                "Gotham Rounded",
                require("./assets/fonts/GothamRnd-Light.otf")
              ],
              /* :: */[
                /* tuple */[
                  "GothamRnd Medium",
                  require("./assets/fonts/GothamRnd-Medium.otf")
                ],
                /* :: */[
                  /* tuple */[
                    "Gotham Bold",
                    require("./assets/fonts/GothamRnd-Bold.otf")
                  ],
                  /* [] */0
                ]
              ]
            ]);
}

function handleLoadingError(error) {
  console.warn(error);
  return /* () */0;
}

function App$app(Props) {
  var match = React.useState((function () {
          return false;
        }));
  var setLoadingComplete = match[1];
  var match$1 = !match[0];
  if (match$1) {
    return React.createElement(Expo.AppLoading, {
                startAsync: loadResourcesAsync,
                onError: handleLoadingError,
                onFinish: (function (param) {
                    return Curry._1(setLoadingComplete, (function (param) {
                                  return true;
                                }));
                  })
              });
  } else {
    return React.createElement(ReactNative.View, {
                style: styles.container,
                children: null
              }, React.createElement(ReactNative.StatusBar, {
                    barStyle: "dark-content"
                  }), React.createElement(make, { }));
  }
}

var app = App$app;

export {
  Authenticator ,
  styles ,
  loadResourcesAsync ,
  handleLoadingError ,
  app ,
  
}
/*  Not a pure module */