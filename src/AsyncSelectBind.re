
type country = {
    .
    "label": string,
    "value": string
    
};

type styleInjector = ReactDOMRe.Style.t => ReactDOMRe.Style.t;

[@bs.deriving abstract]
type styleOverrides = {
  [@bs.optional]
  menu: styleInjector,
  [@bs.optional]
  control: styleInjector,
  [@bs.optional]
  option: styleInjector,
};

type value = Some(string);

[@bs.module "react-select/async"] [@react.component]
external make: (
    ~className: string=?,
    ~cacheOptions: bool=?,
    ~menuIsOpen: bool=?,
    ~defaultValue: country=?,
    ~onChange: Js.nullable('a) => unit=?,
    ~isSearchable: bool=?,
    ~autoFocus: bool=?,
    ~isClearable: bool=?,
    ~defaultOptions: bool=?,
    ~loadOptions: (string) => Js.Promise.t('a),
    ~getOptionLabel:(country) => React.element=?,
    ~styles: styleOverrides=?, 
) => React.element = "default";