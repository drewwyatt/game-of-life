[@react.component]
let make = (~x, ~y) =>
  <rect
    x={string_of_int(x * 10) ++ "px"}
    y={string_of_int(y * 10) ++ "px"}
    width="10px"
    height="10px"
  />;