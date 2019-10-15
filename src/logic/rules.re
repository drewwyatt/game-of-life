type rule = (Board.t, Cell.t) => Cell.t;

let _livingNeighborsFor = (board: Board.t, idx) =>
  board->Board.neighborsFor(idx)
  |> Array.to_list
  |> Cell.is_alive->Board.pipe_idx(board)->List.filter;

/**
 * Any live cell with fewer than two live neighbors dies, as if by underpopulation.
 */
let _noUnderpopulatedCells: rule =
  (board, (state, idx)) =>
    if (state == Cell.Dead) {
      (state, idx);
    } else {
      _livingNeighborsFor(board, idx) |> List.length < 2 ?
        (Cell.Dead, idx) : (Cell.Alive, idx);
    };

/**
 * Any live cell with more than three live neighbours dies, as if by overpopulation.
 */
let _noOverpopulatedCells: rule =
  (board, (state, idx)) =>
    if (state == Cell.Dead) {
      (state, idx);
    } else {
      _livingNeighborsFor(board, idx) |> List.length > 3 ?
        (Cell.Dead, idx) : (Cell.Alive, idx);
    };

/**
* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/
let _allowReproduction: rule =
  (board, (state, idx)) =>
    if (state == Cell.Alive) {
      (state, idx);
    } else {
      _livingNeighborsFor(board, idx) |> List.length == 3 ?
        (Cell.Alive, idx) : (Cell.Dead, idx);
    };

let apply: rule =
  (board, (state, idx)) =>
    state == Cell.Dead ?
      _allowReproduction(board, (state, idx)) :
      _noOverpopulatedCells(board, (state, idx))
      |> _noUnderpopulatedCells(board);