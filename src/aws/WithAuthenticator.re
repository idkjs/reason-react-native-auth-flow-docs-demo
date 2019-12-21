[@bs.module "aws-amplify-react-native"]
// takes a react component and returns a react component with the same signature
external withAuthenticator:
  (React.component('props),~theme:Js.t('a)=?,unit) => React.component('props) =
  "withAuthenticator";
    // to leave option empty, at call site, use `let make = withAuthenticator(make,());`
  // external withAuthenticator:
  // (React.component('props),~theme:Js.t('a)=?) => React.component('props) =
  // "withAuthenticator";
  // to leave option empty, at call site, use `let make = withAuthenticator(make,~theme=Js.Obj.empty());`
