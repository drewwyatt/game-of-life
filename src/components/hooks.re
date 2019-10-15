let useInterval = (cb: unit => unit, delay) => {
  let savedCallback = React.useRef(cb);

  React.useEffect1(
    () => {
      let tick = () => savedCallback->React.Ref.current();
      let id = Js.Global.setInterval(tick, delay);

      Some(() => Js.Global.clearInterval(id));
    },
    [|delay|],
  );
};

let useBoard = (width, height, startingCells) => {
  let (board, setBoard) =
    React.useState(() => Board.make(width, height, startingCells));
  useInterval(
    () => {
      let cells =
        board.cells
        |> Array.map(Rules.noUnderpopulatedCells(board))
        |> Array.to_list
        |> List.filter(((s, _)) => s == Cell.Alive)
        |> List.map(((_, i)) => i);

      setBoard(_ => Board.make(board.width, board.height, cells));
      ();
    },
    1000,
  );

  board;
};