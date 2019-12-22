open ReactNative;
Amplify.configure(AwsExports.config);
API.configure(AwsExports.config);

open Expo;

let styles =
  StyleSheet.create(
    Style.{
      "container":
        style(~flex=1., ~backgroundColor=Theme.Colors.primaryLight, ()),
    },
  );
YellowBox.ignoreWarnings([|
  "Possible Unhandled Promise Rejection",
  "Remote debugger",
  "UIManager['getConstants']",
|]);

let loadResourcesAsync = () => {
  Font.loadAsync([
    (
      "Gotham Rounded",
      Packager.require("./assets/fonts/GothamRnd-Light.otf"),
    ),
    (
      "GothamRnd Medium",
      Packager.require("./assets/fonts/GothamRnd-Medium.otf"),
    ),
    ("Gotham Bold", Packager.require("./assets/fonts/GothamRnd-Bold.otf")),
  ]);
};

let handleLoadingError = error => {
  // In this case, you might want to report the error to your error reporting
  // service, for example Sentry
  error->Js.Console.warn;
};

[@react.component]
let app = () => {
  let (isLoadingComplete, setLoadingComplete) = React.useState(() => false);

  !isLoadingComplete
    ? <AppLoading
        startAsync=loadResourcesAsync
        onError=handleLoadingError
        onFinish={_ => setLoadingComplete(_ => true)}
      />
    : <View style=styles##container>
        <StatusBar barStyle=`darkContent />
        <Authenticated> <AppNavigator /> </Authenticated>
      </View>;
};

