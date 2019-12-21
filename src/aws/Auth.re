// // type t;
// // [@bs.module "@aws-amplify/auth"] external auth: t = "default";
[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external signOut: unit => unit = "signOut";
// [@bs.module "aws-amplify"][@bs.scope "Auth"]
// external signOut: unit => unit = "signOut";

// let signOutUser = () => signOut();

// // [@bs.module "@aws-amplify/auth"]
// // external currentCredentials: unit => Js.Promise.t('a) =
// //   "currentCredentials";

// // let getCurrentCredentials =
// //   Js.Promise.(
// //     currentCredentials()
// //     |> then_(result =>
// //          // Js.log2("getCurrentCredentials: ",result);
// //          // Js.log(result);
// //          resolve(
// //            result,
// //          )
// //        ));
// [@bs.module "@aws-amplify/auth"][@bs.scope "Auth"]
// external currentAuthenticatedUser: unit => Js.Promise.t(Js.Json.t) =
//   "currentAuthenticatedUser";
[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external getCurrentAuthenticatedUser: unit => Js.Promise.t('a) =
  "currentAuthenticatedUser";
let getCurrentAuthUser = () => getCurrentAuthenticatedUser();
// [@bs.module "@aws-amplify/auth"][@bs.scope "Auth"]
// external getCurrentAuthenticatedUser: unit => Js.Promise.t('a) =
//   "currentAuthenticatedUser";
// let getCurrentAuthUser = () => getCurrentAuthenticatedUser();
// /* use typa 'a because doesnt matter what the response is. */
[@bs.module "aws-amplify"][@bs.scope "Auth"]
external currentAuthenticatedUserTypeA: unit => Js.Promise.t('a) =
  "currentAuthenticatedUser";
let currentAuthUser =
  currentAuthenticatedUserTypeA()
  |> Js.Promise.then_(res => Js.Promise.resolve(res));
// let getToken = () => {
//   open PromiseMonad;
//   Belt.Result.(
//     getCurrentSession()
//     >>= (response => Ok(response) |> return)
//     >>| (err => Error(err) |> return)
//   );
// };

// let getUser = () => {
//   PromiseMonad.(
//     Belt.Result.(
//       currentAuthenticatedUser()
//       >>= (response => Ok(response) |> return)
//       >>| (err => Error(err) |> return)
//     )
//   );
// };

// let getToken = () =>
//   PromiseMonad.(
//     getCurrentAuthenticatedUser()
//     >>= (
//       response => {
//         Belt.Option.(
//           response
//           |> (
//             r => {
//               // Js.log2("GET_USER_RESPONSE", r);
//               let jwtToken =
//                 r##signInUserSession
//                 ->flatMap(session => session##accessToken)
//                 ->flatMap(accessToken => accessToken##jwtToken);

//               // Js.log2("GET_USER_JWT_TOKEN: ", jwtToken);

//               return(jwtToken);
//             }
//           )
//         );
//       }
//     )
//   );
