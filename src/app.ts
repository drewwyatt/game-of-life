import { Application } from 'pixi.js'
import { Grid } from './grid'
import { createRuleset, noUnderpopulatedCells } from './rules'

// Add grid to screen
const app = new Application(0, 0, { backgroundColor: 0x1099bb })
const grid = new Grid()
app.stage.addChild(...grid.cells)

// Turn some cells on
grid
  .toggle(0)
  .toggle(2)
  .toggle(16)
  .toggle(19)
  .toggle(34)
  .toggle(42)

// Start loop
setInterval(createRuleset(grid, [noUnderpopulatedCells]), 1000)

export default app
