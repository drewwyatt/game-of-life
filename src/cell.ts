import { Graphics } from 'pixi.js'

const DEAD_COLOR = 0xffffff
const ALIVE_COLOR = 0x000000
export const SIZE = 20

export enum CellState {
  alive,
  dead
}

export type Cell = Graphics & { state: CellState }

export const makeCell = (x: number, y: number): Cell => {
  const cell = new Graphics() as Cell
  cell.beginFill(DEAD_COLOR)
  cell.drawRect(x, y, SIZE, SIZE)
  cell.endFill()
  cell.state = CellState.dead

  return cell
}

export const kill = (cell: Cell): Cell => {
  console.log('killing:', cell)
  cell.state = CellState.dead
  const { x, y } = cell.getGlobalPosition()
  cell.clear()
  cell.beginFill(DEAD_COLOR)
  cell.drawRect(x, y, SIZE, SIZE)
  cell.endFill()
  return cell
}

export const resurrect = (cell: Cell): Cell => {
  cell.state = CellState.alive
  const { x, y } = cell.getGlobalPosition()
  cell.clear()
  cell.beginFill(ALIVE_COLOR)
  cell.drawRect(x, y, SIZE, SIZE)
  cell.endFill()
  return cell
}
