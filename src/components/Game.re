[@react.component]
let make = () => {
  let board = Hooks.useBoard(5, 5, [5, 6, 7]);
  let cells =
    board.cells
    |> Array.map(Space.props_of_cell(board))
    |> Array.map(({x, y, state}: Space.props) =>
         <Space key={x->string_of_int ++ y->string_of_int} x y state />
       );
  <main> <Grid> cells->ReasonReact.array </Grid> </main>;
};