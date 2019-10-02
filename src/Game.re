[@react.component]
let make = () => {
  let cells =
    Board.make(5, 5, [1, 3, 5, 7, 9])->Board.cellPropsGet
    |> Array.map(({x, y, state}: Board.cellProps) => <Cell x y state />);
  <main> <Grid> cells->ReasonReact.array </Grid> </main>;
};