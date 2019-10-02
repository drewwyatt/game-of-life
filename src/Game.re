[@react.component]
let make = () => {
  let cells =
    Board.make(5, 5)->Board.cellPropsGet
    |> Array.map(({x, y, state}: Board.cellProps) => <Cell x y state />);
  <main> <Grid> cells->ReasonReact.array </Grid> </main>;
};