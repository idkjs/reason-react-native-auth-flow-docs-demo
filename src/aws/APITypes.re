type executionResult = {
  errors: option(array(string)),
  data: option(Js.Json.t),
};
/* https://github.com/aws-amplify/amplify-js/blob/867412030de57fd74078b609252de6f7f81ad331/packages/api/src/API.ts#L31-L34 */
type graphqlOperation = {
  query: string,
  variables: option(Js.Json.t),
};

type operation = graphqlOperation => Js.Promise.t(executionResult);

type onCreateMessage = {
  __typename: string,
  message: string,
};

type event = {value}
and value = {data: onCreateMessage};

type errorValue = {message: string};

type observerLike('event) = {
  next: event => unit,
  error: errorValue => unit,
  complete: unit => unit,
};

type observableLike('value) = {
  subscribe:
    observerLike('value) => {. [@bs.meth] "unsubscribe": unit => unit},
};

type level =
  | Error
  | Warn
  | Info
  | Verbose
  | Debug
  | Silly;
let levelToString =
  fun
  | Error => "ERROR"
  | Warn => "WARN"
  | Info => "INFO"
  | Verbose => "VERBOSE"
  | Debug => "DEBUG"
  | Silly => "SILLY";
type hubEvent = [
  | `signIn
  | `signUp
  | `signOut
  | `signIn_failure
  | `configured
];
type payloadJs = {
  hubEvent,
  data: Js.Nullable.t(Js.t({.})),
  message: string,
};

type attributes = {
  sub: string,
  email_verified: bool,
  email: string,
  phone_number: Js.Nullable.t(string),
};
type userInfo = {
  username: string,
  attributes,
};
let fromJsAttrs = attributes => {
  sub: attributes##sub,
  email_verified: attributes##email_verified,
  email: attributes##email,
  phone_number: Js.Nullable.return(attributes##phone_number),
};
let fromJs = data => {
  username: data##username,
  attributes: fromJsAttrs(data##attributes),
};

type comment = {
  id: option(string),
  talkId: option(string),
  message: string,
  // createdAt: Js.Date.t,
  createdAt: string,
  createdBy: string,
  deviceId: option(string),
};
let commentToRecord: Js.t('a) => comment =
  data => {
    id: data##id,
    talkId: data##talkId,
    message: data##message,
    createdAt: data##createdAt,
    createdBy: data##createdBy,
    deviceId: data##deviceId,
  };