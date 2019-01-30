import { Cell } from './cell'
import { Grid } from './grid'

const apply = <A, B extends (a: A) => any>(a: A) => (b: B) => b(a)

type Mutation = [Cell[], Cell[]]
type Rule = (grid: Grid) => Mutation

/**
 * Any live cell with fewer than two live neighbors dies, as if by underpopulation.
 */
export const noUnderpopulatedCells: Rule = grid => [
  grid.livingCells.filter(cell => grid.getLivingNeighbors(cell.index).length < 2),
  []
]

export const createRuleset = (grid: Grid, rules: Rule[]) => () => {
  rules.map(apply(grid)).forEach(([toKill, toRes]: Mutation) => {
    toKill.forEach(({ index }) => grid.kill(index))
    toRes.forEach(({ index }) => grid.resurrect(index))
  })
}

// TODO:
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
