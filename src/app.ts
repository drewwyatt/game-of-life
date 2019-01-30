import { Application } from 'pixi.js'
import { Grid } from './grid'
import { createRuleset, noUnderpopulatedCells, noOverpopulatedCells } from './rules'

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
  .toggle(60)
  .toggle(61)
  .toggle(62)
  .toggle(75)
  .toggle(76)
  .toggle(77)
  .toggle(100)
  .toggle(101)
  .toggle(115)
  .toggle(116)

// Start loop
setInterval(createRuleset(grid, [noUnderpopulatedCells, noOverpopulatedCells]), 1000)

export default app
