// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Utils from "./utils/Utils.bs.js";
import * as React from "react";
import * as GlobalStyle from "./GlobalStyle.bs.js";
import * as ReactNative from "react-native";

function AuthLoadingScreen(Props) {
  var navigation = Props.navigation;
  React.useEffect((function () {
          Utils.checkAuthWithRoute(navigation);
          return (function (param) {
                    return /* () */0;
                  });
        }), []);
  return React.createElement(ReactNative.View, {
              style: GlobalStyle.styles.container,
              children: null
            }, React.createElement(ReactNative.ActivityIndicator, { }), React.createElement(ReactNative.StatusBar, {
                  barStyle: "default"
                }));
}

var make = AuthLoadingScreen;

export {
  make ,
  
}
/* Utils Not a pure module */
