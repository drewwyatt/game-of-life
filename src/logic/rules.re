/**
 * Any live cell with fewer than two live neighbors dies, as if by underpopulation.
 */
let noUnderpopulatedCells = (board: Board.t) =>
  board.cells->Array.to_list
  |> List.filter(((state, _)) => state == Board.Alive);

/*

 const filterLiveCellsOnNeighborLength = (grid: Grid, predicate: (length: number) => boolean): Cell[] =>
   grid.livingCells.filter(({ index }) => predicate(grid.getLivingNeighbors(index).length))

 const filterDeadCellsOnNeighborLength = (grid: Grid, predicate: (length: number) => boolean): Cell[] =>
   grid.deadCells.filter(({ index }) => predicate(grid.getLivingNeighbors(index).length))

  */