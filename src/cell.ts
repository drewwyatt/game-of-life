import { Graphics } from 'pixi.js'

const COLOR = 0xffffff
export const SIZE = 20

export enum CellState {
  alive,
  dead
}

export type Cell = Graphics & { state: CellState }

export const makeCell = (x: number, y: number): Cell => {
  const cell = new Graphics() as Cell
  cell.beginFill(COLOR)
  cell.drawRect(x, y, SIZE, SIZE)
  cell.endFill()
  cell.state = CellState.dead

  return cell
}
