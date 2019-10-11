/**
 * Any live cell with fewer than two live neighbors dies, as if by underpopulation.
 */
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

/*

 const filterLiveCellsOnNeighborLength = (grid: Grid, predicate: (length: number) => boolean): Cell[] =>
   grid.livingCells.filter(({ index }) => predicate(grid.getLivingNeighbors(index).length))

 const filterDeadCellsOnNeighborLength = (grid: Grid, predicate: (length: number) => boolean): Cell[] =>
   grid.deadCells.filter(({ index }) => predicate(grid.getLivingNeighbors(index).length))

  */