import { compose, equals, filter, map, not, prop, range } from 'sanctuary'
import { Cell, makeCell, SIZE as CELL_SIZE, kill, resurrect, CellState } from './cell'

const highest = (a: number) => (b: number) => (a > b ? a : b)
const lowest = (a: number) => (b: number) => (a < b ? a : b)
type Coords = { x: number; y: number }

export class Grid {
  static NUMBER_OF_COLUMNS = 15
  static NUMBER_OF_ROWS = Grid.NUMBER_OF_COLUMNS
  static NUMBER_OF_CELLS = Grid.NUMBER_OF_COLUMNS * Grid.NUMBER_OF_ROWS

  static Filters: Record<string, (c: Cell) => boolean> = {
    isDead: compose(equals(CellState.dead))(prop('state')),
    isLiving: compose(equals(CellState.alive))(prop('state'))
  }

  cells: Cell[]

  constructor() {
    this.cells = this.makeCells(Grid.NUMBER_OF_CELLS)
  }

  get deadCells(): Cell[] {
    return filter(Grid.Filters.isDead)(this.cells)
  }

  get livingCells(): Cell[] {
    return filter(Grid.Filters.isLiving)(this.cells)
  }

  getNeighbors = (idx: number): Cell[] => {
    const { x, y } = this.coordsForIndex(idx)
    return this.getNeighboringCoords(x, y).map(({ x, y }) => this.get(x, y))
  }

  getLivingNeighbors = (idx: number): Cell[] => {
    return this.getNeighbors(idx).filter(Grid.Filters.isLiving)
  }

  toggle = (idx: number): this => {
    this.cells[idx].state === CellState.alive ? this.kill(idx) : this.resurrect(idx)
    return this
  }

  kill = (idx: number): this => {
    const cell = this.cells[idx]
    const { x, y } = this.positionForIndex(idx)
    kill(cell, x, y)
    return this
  }

  resurrect = (idx: number): this => {
    const cell = this.cells[idx]
    const { x, y } = this.positionForIndex(idx)
    resurrect(cell, x, y)
    return this
  }

  get = (x: number, y: number): Cell => {
    return this.cells[this.indexForCoords(x, y)]
  }

  private getNeighboringCoords = (x: number, y: number): Coords[] => {
    const xVals = range(highest(0)(x - 1))(lowest(Grid.NUMBER_OF_COLUMNS)(x + 2))
    const yVals = range(highest(0)(y - 1))(lowest(Grid.NUMBER_OF_ROWS)(y + 2))
    return this.combineCords(xVals, yVals).filter(compose(not)(equals({ x, y })))
  }

  private combineCords = (xCords: number[], yCords: number[]): Coords[] => {
    return xCords.reduce((coords: Coords[], x: number) => [...coords, ...yCords.map(y => ({ x, y }))], [])
  }

  private makeCells = (numberOfCells: number) => compose(map(this.mapIndexToCell))(range(0))(numberOfCells) as Cell[]

  private coordsForIndex = (idx: number) => ({
    x: idx % Grid.NUMBER_OF_COLUMNS,
    y: Math.floor(idx / Grid.NUMBER_OF_COLUMNS)
  })

  private indexForCoords = (x: number, y: number): number => y * Grid.NUMBER_OF_COLUMNS + x

  private positionForIndex = (idx: number) => {
    const { x, y } = this.coordsForIndex(idx)
    return {
      x: x * CELL_SIZE + x,
      y: y * CELL_SIZE + y
    }
  }

  private mapIndexToCell = (idx: number): Cell => {
    const { x, y } = this.positionForIndex(idx)
    return makeCell(x, y, idx)
  }
}
