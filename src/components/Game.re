[@react.component]
let make = () => {
  Hooks.useInterval(() => "Woop"->Js.log, 1000);
  let cells =
    Board.make(5, 5, [1, 3, 5, 7, 9])->GameOfLife.Board.cellPropsGet
    |> Array.map(({x, y, state}: Board.cellProps) =>
         <Cell key={x->string_of_int ++ y->string_of_int} x y state />
       );
  <main> <Grid> cells->ReasonReact.array </Grid> </main>;
};