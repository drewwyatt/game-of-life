import { gt, lt } from 'sanctuary'
import { Cell } from './cell'
import { Grid } from './grid'

const apply = <A, B extends (a: A) => any>(a: A) => (b: B) => b(a)

type Mutation = [Cell[], Cell[]]
type Rule = (grid: Grid) => Mutation

const filterOnNeighborLength = (grid: Grid, predicate: (length: number) => boolean): Cell[] =>
  grid.livingCells.filter(({ index }) => predicate(grid.getLivingNeighbors(index).length))

/**
 * Any live cell with fewer than two live neighbors dies, as if by underpopulation.
 */
export const noUnderpopulatedCells: Rule = grid => [filterOnNeighborLength(grid, lt(2)), []]

/**
 * Any live cell with more than three live neighbors dies, as if by overpopulation.
 */
export const noOverpopulatedCells: Rule = grid => [filterOnNeighborLength(grid, gt(3)), []]

export const createRuleset = (grid: Grid, rules: Rule[]) => () => {
  rules.map(apply(grid)).forEach(([toKill, toRes]: Mutation) => {
    toKill.forEach(({ index }) => grid.kill(index))
    toRes.forEach(({ index }) => grid.resurrect(index))
  })
}

// TODO:
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
