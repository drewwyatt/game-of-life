type cellState =
  | Alive
  | Dead;

let resurrect = (indexes, cells) =>
  cells
  |> Array.mapi((i, existing) =>
       List.exists(idx => idx == i, indexes) ? Alive : existing
     );

type t = {
  width: int,
  height: int,
  cells: array(cellState),
};

let make = (width, height, startingIndexes) => {
  width,
  height,
  cells: Array.make(width * height, Dead) |> resurrect(startingIndexes),
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