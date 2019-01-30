import { Grid } from './grid'

const apply = <A, B extends (a: A) => any>(a: A) => (b: B) => b(a)
type Rule = (grid: Grid) => Grid

/**
 * Any live cell with fewer than two live neighbors dies, as if by underpopulation.
 */
export const noUnderpopulatedCells = (grid: Grid): Grid => {
  grid.livingCells.filter(cell => grid.getLivingNeighbors(cell.index).length < 2).forEach(c => grid.kill(c.index))
  return grid
}

export const createRuleset = (grid: Grid, rules: Rule[]) => () => {
  rules.forEach(apply(grid))
}

// TODO:
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
