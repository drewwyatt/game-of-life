type coords = (int, int);

let resurrect = (indexes, cells) =>
  cells
  |> Array.map(((state, i)) =>
       indexes |> List.exists(Utils.eq(i)) ? (Cell.Alive, i) : (state, i)
     );

type t = {
  width: int,
  height: int,
  cells: array(Cell.t),
};

let make = (width, height, startingIndexes) => {
  width,
  height,
  cells:
    Array.make(width * height, Cell.Dead)
    |> Array.mapi((i, state) => (state, i))
    |> resurrect(startingIndexes),
};

let coordsForIdx = (board, idx) => (idx mod board.width, idx / board.width);

let is_left_border = (board, idx) => idx mod board.width == 0;
let is_right_border = (board, idx) => idx mod board.width == board.width - 1;
let is_top_border = (board, idx) => idx < board.width;
let is_bottom_border = (board, idx) =>
  idx + board.width >= board.width * board.height;

let make_neighbors_for_axis = (~predicates, ~diff, board, idx) => {
  let (prev_predicate, next_predicate) = predicates;
  let prev_idx: option(int) =
    prev_predicate(board, idx) ? None : Some(idx - diff);
  let next_idx: option(int) =
    next_predicate(board, idx) ? None : Some(idx + diff);
  [|prev_idx, next_idx|]->Belt.Array.keepMap(a => a);
};

let x_neighboars_for_board_and_idx =
  make_neighbors_for_axis(
    ~predicates=(is_left_border, is_right_border),
    ~diff=1,
  );
let y_neighboars_for_width_board_and_idx =
  make_neighbors_for_axis(~predicates=(is_top_border, is_bottom_border));

let neighborsFor = (board, idx) =>
  Array.concat([
    x_neighboars_for_board_and_idx(board, idx),
    y_neighboars_for_width_board_and_idx(~diff=board.width, board, idx),
  ]);

let pipe_idx = (fn, board, idx) => fn(board.cells[idx]);

/* let indexForCoords = (board, (x, y)) => y * board.width + x; */