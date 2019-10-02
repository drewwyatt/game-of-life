type cellState =
  | Alive
  | Dead;

type t = {
  width: int,
  height: int,
  cells: array(cellState),
};

let make = (width, height) => {
  width,
  height,
  cells: Array.make(width * height, Dead),
};

type cellProps = {
  x: int,
  y: int,
  state: cellState,
};

let toCellProps = (board: t, idx: int, state: cellState) => {
  x: idx mod board.width,
  y: idx / board.width,
  state,
};

let cellPropsGet = (board: t) =>
  board.cells |> Array.mapi(toCellProps(board));