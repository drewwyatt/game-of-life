import { Application } from 'pixi.js'
import { Grid } from './grid'

const app = new Application(0, 0, { backgroundColor: 0x1099bb })
const grid = new Grid()
app.stage.addChild(...grid.cells)

export default app
