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

let neighborsFor = (board, idx) => {
  let (x, y) = board->coordsForIdx(idx);
  Js.log("coords for idx: " ++ idx->string_of_int);
  Js.log("  >  (" ++ x->string_of_int ++ ", " ++ y->string_of_int ++ ")");
  open Utils;
  let xVals = range(highest(0, x - 1), lowest(board.width, x + 2));
  Js.log("xvals:");
  xVals |> List.fold_left((_, v) => Js.log("  > " ++ v->string_of_int), ());
  let yVals = range(highest(0, y - 1), lowest(board.height, y + 2));
  Js.log("yvals:");
  yVals |> List.fold_left((_, v) => Js.log("  > " ++ v->string_of_int), ());
  let l =
    xVals
    |> List.fold_left(
         (acc, thisX) => {
           let pairs =
             yVals
             |> List.map(thisY => (thisX, thisY))
             |> List.filter(pair => pair != (x, y));
           List.concat([acc, pairs]);
         },
         [],
       );
  Js.log("pairs:");
  l
  |> List.fold_left(
       (_, (x, y)) =>
         Js.log("  > " ++ x->string_of_int ++ "," ++ y->string_of_int),
       (),
     );
  l;
};

let indexForCoords = (board, (x, y)) => y * board.width + x;