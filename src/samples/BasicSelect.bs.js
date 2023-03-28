'use strict';

var React = require("react");
var ReactSelect = require("react-select").default;

var options = [
  {
    value: "one",
    label: "One"
  },
  {
    value: "two",
    label: "Two"
  },
  {
    value: "three",
    label: "Three"
  },
  {
    value: "four",
    label: "Four"
  },
  {
    value: "five",
    label: "Five"
  },
  {
    value: "six",
    label: "Six"
  },
  {
    value: "seven",
    label: "Seven"
  },
  {
    value: "eight",
    label: "Eight"
  },
  {
    value: "nine",
    label: "Nine"
  },
  {
    value: "ten",
    label: "Ten"
  }
];

function BasicSelect(Props) {
  console.log(options);
  return React.createElement(ReactSelect, {
              options: options
            });
}

var make = BasicSelect;

exports.options = options;
exports.make = make;
/* react Not a pure module */
