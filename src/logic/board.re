type cellState =
  | Alive
  | Dead;

type cell = (cellState, int);

type coords = (int, int);

let resurrect = (indexes, cells) =>
  cells
  |> Array.map(((state, i)) =>
       indexes |> List.exists(Utils.eq(i)) ? (Alive, i) : (state, i)
     );

type t = {
  width: int,
  height: int,
  cells: array(cell),
};

let make = (width, height, startingIndexes) => {
  width,
  height,
  cells:
    Array.make(width * height, Dead)
    |> Array.mapi((i, state) => (state, i))
    |> resurrect(startingIndexes),
};

type cellProps = {
  x: int,
  y: int,
  state: cellState,
};

let coordsForIdx = (board, idx) => (idx mod board.width, idx / board.width);

let neighborsFor = (board, idx) => {
  let (x, y) = board->coordsForIdx(idx);
  open Utils;
  let xVals = range(highest(0, x - 1), lowest(board.width, x + 1));
  let yVals = range(highest(0, y - 1), lowest(board.height, y + 1));
  Belt.List.zip(xVals, yVals);
};

let indexForCoords = (board, (x, y)) => y * board.width + x;

let toCellProps = (board: t, (state, idx)) => {
  let (x, y) = board->coordsForIdx(idx);
  {x, y, state};
};

let cellPropsGet = (board: t) =>
  board.cells |> Array.map(toCellProps(board));