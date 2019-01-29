import { range } from 'sanctuary'
import { Cell, makeCell, SIZE as CELL_SIZE, kill, resurrect, CellState } from './cell'

export class Grid {
  static NUMBER_OF_COLUMNS = 5
  static NUMBER_OF_ROWS = Grid.NUMBER_OF_COLUMNS
  static NUMBER_OF_CELLS = Grid.NUMBER_OF_COLUMNS * Grid.NUMBER_OF_ROWS

  cells: Cell[]

  constructor() {
    this.cells = this.makeCells(Grid.NUMBER_OF_CELLS)
  }

  toggle = (idx: number): this => {
    const cell = this.cells[idx]
    this.cells[idx] = cell.state === CellState.alive ? kill(cell) : resurrect(cell)
    return this
  }

  private makeCells = (numberOfCells: number): Cell[] => range(0)(numberOfCells).map(this.mapIndexToCell)

  private coordsForIndex = (idx: number) => ({
    x: idx % Grid.NUMBER_OF_COLUMNS,
    y: Math.floor(idx / Grid.NUMBER_OF_COLUMNS)
  })

  private mapIndexToCell = (idx: number): Cell => {
    const { x, y } = this.coordsForIndex(idx)
    return makeCell(x * CELL_SIZE + x, y * CELL_SIZE + y)
  }
}
