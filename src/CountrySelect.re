open ReactDOMRe.Style;

let styleOverrides =
  AsyncSelectBind.styleOverrides(
    ~menu=
      style =>
        combine(
          style,
          make(
            ~marginBottom= "5px",
          ~background="white",
          ~border= "1px solid rgba(0, 0, 0, 0.2)",
          ~boxShadow= "0px 0px 0px 1px rgba(0, 0, 0, 0.08), 0px 3px 18px rgba(0, 0, 0, 0.15)",
          ~borderRadius= "2px",
          ~width= "280px",
          ~color="#333333",
          ~fontWeight= "Light",
          ~font= "Arial",
            (),
          ),
        ),
    ~control=
      style =>
        combine(
          style,
          make(~background="white",
        ~width= "200px",
        ~height= "30px",
        ~border= "1px solid rgba(0, 0, 0, 0.2)",
        ~borderRadius= "3px", ()),
        ),
    ~option=style => combine(style, make(
        ~fontSize= "14px",
        ~fontStyle= "normal",
        ~color="#333333",
        ~fontWeight= "400",
         ()
         )),
    ()
  );
type country = {
    .
    "label": string,
    "value": string
    
};

module Decode = {
  let country = country =>
    Json.Decode.{
      "value": field("value", string, country),
      "label": field("label", string, country),
    };
    let countries = json : Js.Array.t(country) => Json.Decode.array(country, json);
};

type url = string;

let url = "https://gist.githubusercontent.com/rusty-key/659db3f4566df459bd59c8a53dc9f71f/raw/4127f9550ef063121c564025f6d27dceeb279623/counties.json";

/* Filtering for options */
let filterCountries = ( countries: Js.Array.t(country), inputValue: string) => {
    Js.Array.filter(country 
    => Js.String.toLowerCase(country##label) 
    |> Js.String.includes(Js.String.toLowerCase(inputValue)),
     countries);
};


/* function for loadOptions */
let loadOptions = (inputValue: string) => {

    Fetch.fetch(url)
    ->Js.Promise.then_(Fetch.Response.json, _)
    ->Js.Promise.then_(json => json -> Decode.countries -> filterCountries(inputValue) -> Js.Promise.resolve, _);
    
};


[@react.component]
let make = (~onChange, ~className) => {
    <div style = {
        make(
            ~display="flex",
            ~justifyContent="center",
            ~alignItems="center",
            ())
    }>
    <AsyncSelectBind 
    className
    onChange={newValue =>
          newValue
          |> Js.Nullable.toOption
          |> onChange
          |> (_ => Js.log(newValue))
        }
    cacheOptions = {true}
    isClearable = {true}
    autoFocus = {true}
    isSearchable = {true}
    styles=styleOverrides
    defaultOptions = {true}
    loadOptions = {loadOptions}
    getOptionLabel = {e=>(
        <div style={
            ReactDOMRe.Style.make(
                ~display= "flex",
                ~justifyContent="flex-start",
                ~alignItems="center",
                (),
            )
        }>
            <span 
            className=[%raw {|`fi fi-${e.value}`|}]
            style = ReactDOMRe.Style.make(
                ~marginRight="8px",
                (),
            )
            ></span>

            {React.string(e##label)}
        </div>
    )}
    />
    </div>
}