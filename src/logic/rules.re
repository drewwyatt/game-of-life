/**
 * Any live cell with fewer than two live neighbors dies, as if by underpopulation.
 */
let noUnderpopulatedCells = (board: Board.t, (state, idx)) =>
  if (state == Cell.Dead) {
    (state, idx);
  } else {
    board->Board.neighborsFor(idx)
    |> Array.to_list
    |> Cell.is_alive->Board.pipe_idx(board)->List.filter
    |> List.length < 2 ?
      (Cell.Dead, idx) : (Cell.Alive, idx);
  };