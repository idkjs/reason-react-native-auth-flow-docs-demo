// [@bs.module "./theme.js"][@bs.scope "colors"] external colors:'a = "default";
open ReactNative;

// let logo =
//   Image.Source.fromRequired(Packager.require("./assets/logo.jpg"));
let dimensions = Dimensions.get(`window);
// let screenWidth = Dimensions.get(`window)##width -. 30.;
let primaryText = "white";

module Colors = {
  let primary = "rgba(18, 25, 50, 1)";
  let primary2 = "rgba(27, 37, 77, 1)";
  let primaryLight = "rgba(27, 37, 77, 1)";
  let primaryDark = "rgba(14, 20, 43, 1)";
  let primaryOpaque = opacity => "rgba(18, 25, 50," ++ opacity ++ ")";
  let primaryText = "white";
  let highlight = "#61dafb";
};

module Typography = {
  let primary = "Gotham Rounded";
  let secondary = "Gotham Rounded";
  let medium = "GothamRnd Medium";
  let bold = "Gotham Bold";
};
