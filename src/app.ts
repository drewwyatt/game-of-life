import { Application } from 'pixi.js'
import { Grid } from './grid'

const app = new Application(0, 0, { backgroundColor: 0x1099bb })
const grid = new Grid()
app.stage.addChild(...grid.cells)

let times = 0
let idx = 0
app.ticker.add(() => {
  if (times < 2) {
    grid.toggle(idx)
    idx = idx + 1 >= grid.cells.length ? 0 : idx + 1
    if (idx === 0) {
      times++
    }
  }
})

export default app
