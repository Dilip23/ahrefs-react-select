type option = {
    .
    "value": string,
    "label": string
};


let options = [|
  {"value": "one", "label": "One"},
  {"value": "two", "label": "Two"},
  {"value": "three", "label": "Three"},
  {"value": "four", "label": "Four"},
  {"value": "five", "label": "Five"},
  {"value": "six", "label": "Six"},
  {"value": "seven", "label": "Seven"},
  {"value": "eight", "label": "Eight"},
  {"value": "nine", "label": "Nine"},
  {"value": "ten", "label": "Ten"},
|];

[@react.component]
let make = () => {
    Js.log(options);
    <BasicSelectBind 
    options
    />
}