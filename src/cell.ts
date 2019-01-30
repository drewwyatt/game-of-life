import { Graphics } from 'pixi.js'

const DEAD_COLOR = 0xffffff
const ALIVE_COLOR = 0x00ff00
export const SIZE = 20

export enum CellState {
  alive,
  dead
}

export type Cell = Graphics & { index: number; state: CellState }

export const makeCell = (x: number, y: number, index: number): Cell => {
  const cell = new Graphics() as Cell
  cell.beginFill(DEAD_COLOR)
  cell.drawRect(x, y, SIZE, SIZE)
  cell.endFill()

  cell.index = index
  cell.state = CellState.dead

  return cell
}

export const kill = (cell: Cell, x: number, y: number): Cell => {
  cell.state = CellState.dead
  cell.clear()
  cell.beginFill(DEAD_COLOR)
  cell.drawRect(x, y, SIZE, SIZE)
  cell.endFill()
  return cell
}

export const resurrect = (cell: Cell, x: number, y: number): Cell => {
  cell.state = CellState.alive
  cell.clear()
  cell.beginFill(ALIVE_COLOR)
  cell.drawRect(x, y, SIZE, SIZE)
  cell.endFill()
  return cell
}
