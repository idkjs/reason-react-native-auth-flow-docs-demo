open ReactNative;
open Theme;
// import default stylesheet from your js library
[@bs.module ("aws-amplify-react-native", "AmplifyTheme")]
external defaultStyles: Js.t('a) = "AmplifyTheme";

// create new button color
let buttonBackgroundColor =
  Style.(style(~backgroundColor=Colors.primaryLight, ()));

// use flatten to change out the old color with the new color
let newButton =
  StyleSheet.flatten([|defaultStyles##button, buttonBackgroundColor|]);

/* logging the button before and after show the change being made
defaultStyles##button-before Object {
  "alignItems": "center",
  "backgroundColor": "#ff9900",
  "padding": 16,
}
defaultStyless##button-after Object {
  "alignItems": "center",
  "backgroundColor": "rgba(27, 37, 77, 1)",
  "padding": 16,
}
Js.log2("defaultStyles##button-before", defaultStyles##button);
defaultStyles##button #= newButton;
Js.log2("defaultStyles##button-after", defaultStyles##button);
*/
// overwrite the original style with your new style
defaultStyles##button #= newButton;
let buttonDisabledColor =
  Style.(style(~backgroundColor=Colors.primaryOpaque("0.6"), ()));
let newButtonDisabled =
  StyleSheet.flatten([|defaultStyles##buttonDisabled, buttonDisabledColor|]);

defaultStyles##buttonDisabled #= newButtonDisabled;
let sectionFooterColor = Style.(style(~color=Colors.primaryLight, ()));
let newSectionFooterLink =
  StyleSheet.flatten([|
    defaultStyles##sectionFooterLink,
    sectionFooterColor,
  |]);
defaultStyles##sectionFooterLink #= newSectionFooterLink;

// convience identifier to to pass to my function which takes a style object.
let theme = defaultStyles;