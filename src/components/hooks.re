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