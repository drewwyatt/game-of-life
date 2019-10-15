/**
 * Any live cell with fewer than two live neighbors dies, as if by underpopulation.
 */
let noUnderpopulatedCells = (board: Board.t, (state, idx)) =>
  if (state == Cell.Dead) {
    (
      /* Js.log(idx->string_of_int ++ ": already dead"); */
      state,
      idx,
    );
  } else {
    board->Board.neighborsFor(idx)
    |> Array.to_list
    |> Cell.is_alive->Board.pipe_idx(board)->List.filter
    |> List.length < 2 ?
      (Cell.Dead, idx) : (Cell.Alive, idx);
  };

/*
 let noUnderpopulatedCells = (board: Board.t, (state, idx)) =>
   state == Board.Dead ?
     (state, idx) :
     board->Board.neighborsFor(idx)
     |> List.map(Board.indexForCoords(board))
     |> List.filter(i => {
          let (s, _) = board.cells->Array.get(i);
          s == Alive;
        })
     |> List.length < 2 ?
       (Board.Dead, idx) : (Board.Alive, idx);
       */

/*

 const filterLiveCellsOnNeighborLength = (grid: Grid, predicate: (length: number) => boolean): Cell[] =>
   grid.livingCells.filter(({ index }) => predicate(grid.getLivingNeighbors(index).length))

 const filterDeadCellsOnNeighborLength = (grid: Grid, predicate: (length: number) => boolean): Cell[] =>
   grid.deadCells.filter(({ index }) => predicate(grid.getLivingNeighbors(index).length))

  */