type props = {
  x: int,
  y: int,
  state: Cell.state,
};

let props_of_cell = (board: Board.t, (state, idx): Cell.t) => {
  let (x, y) = board->Board.coordsForIdx(idx);
  {x, y, state};
};

[@react.component]
let make = (~x, ~y, ~state) =>
  <rect
    x={string_of_int(x * 10) ++ "px"}
    y={string_of_int(y * 10) ++ "px"}
    width="10px"
    height="10px"
    className={
      switch (state) {
      | Cell.Alive => "alive"
      | Cell.Dead => "dead"
      }
    }
  />;