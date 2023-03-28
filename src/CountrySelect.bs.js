'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");
var Async = require("react-select/async").default;

var styleOverrides = {
  menu: (function (style) {
      return Object.assign({}, style, {
                  background: "white",
                  border: "1px solid rgba(0, 0, 0, 0.2)",
                  color: "#333333",
                  font: "Arial",
                  fontWeight: "Light",
                  marginBottom: "5px",
                  width: "280px",
                  borderRadius: "2px",
                  boxShadow: "0px 0px 0px 1px rgba(0, 0, 0, 0.08), 0px 3px 18px rgba(0, 0, 0, 0.15)"
                });
    }),
  control: (function (style) {
      return Object.assign({}, style, {
                  background: "white",
                  border: "1px solid rgba(0, 0, 0, 0.2)",
                  height: "30px",
                  width: "200px",
                  borderRadius: "3px"
                });
    }),
  option: (function (style) {
      return Object.assign({}, style, {
                  color: "#333333",
                  fontSize: "14px",
                  fontStyle: "normal",
                  fontWeight: "400"
                });
    })
};

function country(country$1) {
  return {
          value: Json_decode.field("value", Json_decode.string, country$1),
          label: Json_decode.field("label", Json_decode.string, country$1)
        };
}

function countries(json) {
  return Json_decode.array(country, json);
}

var Decode = {
  country: country,
  countries: countries
};

var url = "https://gist.githubusercontent.com/rusty-key/659db3f4566df459bd59c8a53dc9f71f/raw/4127f9550ef063121c564025f6d27dceeb279623/counties.json";

function filterCountries(countries, inputValue) {
  return countries.filter(function (country) {
              return country.label.toLowerCase().includes(inputValue.toLowerCase());
            });
}

function loadOptions(inputValue) {
  var __x = fetch(url);
  var __x$1 = __x.then(function (prim) {
        return prim.json();
      });
  return __x$1.then(function (json) {
              return Promise.resolve(filterCountries(Json_decode.array(country, json), inputValue));
            });
}

function CountrySelect(Props) {
  var onChange = Props.onChange;
  var className = Props.className;
  return React.createElement("div", {
              style: {
                display: "flex",
                alignItems: "center",
                justifyContent: "center"
              }
            }, React.createElement(Async, {
                  className: className,
                  cacheOptions: true,
                  onChange: (function (newValue) {
                      Curry._1(onChange, (newValue == null) ? undefined : Caml_option.some(newValue));
                      console.log(newValue);
                      
                    }),
                  isSearchable: true,
                  autoFocus: true,
                  isClearable: true,
                  defaultOptions: true,
                  loadOptions: loadOptions,
                  getOptionLabel: (function (e) {
                      return React.createElement("div", {
                                  style: {
                                    display: "flex",
                                    alignItems: "center",
                                    justifyContent: "flex-start"
                                  }
                                }, React.createElement("span", {
                                      className: (`fi fi-${e.value}`),
                                      style: {
                                        marginRight: "8px"
                                      }
                                    }), e.label);
                    }),
                  styles: styleOverrides
                }));
}

var make = CountrySelect;

exports.styleOverrides = styleOverrides;
exports.Decode = Decode;
exports.url = url;
exports.filterCountries = filterCountries;
exports.loadOptions = loadOptions;
exports.make = make;
/* react Not a pure module */
