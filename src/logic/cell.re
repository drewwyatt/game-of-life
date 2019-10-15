type state =
  | Alive
  | Dead;

type index = int;

type t = (state, index);

let is_alive = ((state, _)) => state == Alive;
let is_dead = ((state, _)) => state == Dead;
let extract_idx = ((_, i)) => i;