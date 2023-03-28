/* [@bs.deriving abstract]
type option = {
    label: string,
    value: string
}; */


[@bs.module "react-select"] [@react.component]
external make: (
    ~options: array('a)
) => React.element = "default";