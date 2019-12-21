
type t = {
  mutable username: string,
  mutable email: string,
  mutable phone_number: string,
  mutable jwtToken: string,
};
let user: t = {username: "", email: "", phone_number: "", jwtToken: ""};
let getName = () => user.username;
let getPhone = () => user.phone_number;
let getEmail = () => user.email;
let getToken = () => user.jwtToken;

let setSession =
  PromiseMonad.(
    Auth.getCurrentAuthUser()
    >>= (
      response => {
        Belt.Option.(
          response
          |> (
            r => {
              // Js.log2("GET_USER_RESPONSE",r)
              let jwtToken =
                r##signInUserSession
                ->flatMap(session => session##accessToken)
                ->flatMap(accessToken => accessToken##jwtToken)
                ->getWithDefault("");
              let email =
                r##signInUserSession
                ->flatMap(session => session##idToken)
                ->flatMap(idToken => idToken##payload)
                ->flatMap(payload => payload##email)
                ->getWithDefault("");
              let phone_number =
                r##signInUserSession
                ->flatMap(session => session##idToken)
                ->flatMap(idToken => idToken##payload)
                ->flatMap(payload => payload##phone_number)
                ->getWithDefault("");
              // Js.log2("GET_USER_RESPONSE_EMAIL",email)

              let username = r##username->getWithDefault("");
              user.username = username;
              user.email = email;
              user.phone_number = phone_number;
              user.jwtToken = jwtToken;
              return(user);
            }
          )
        );
      }
    )
  );
