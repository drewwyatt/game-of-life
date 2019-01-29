import { Application } from 'pixi.js'
import { Grid } from './grid'

const app = new Application(0, 0, { backgroundColor: 0x1099bb })
const grid = new Grid()
app.stage.addChild(...grid.cells)

let idx = 0
app.ticker.add(() => {
  grid.toggle(idx)
  idx = idx + 1 > grid.cells.length ? 0 : idx + 1
})

export default app
