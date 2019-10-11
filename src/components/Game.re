[@react.component]
let make = () => {
  Hooks.useInterval(() => "Woop"->Js.log, 1000);
  let board = Hooks.useBoard(5, 5, [1, 2, 3, 4, 5, 6, 7, 8, 9]);
  let cells =
    board->GameOfLife.Board.cellPropsGet
    |> Array.map(({x, y, state}: Board.cellProps) =>
         <Cell key={x->string_of_int ++ y->string_of_int} x y state />
       );
  <main> <Grid> cells->ReasonReact.array </Grid> </main>;
};