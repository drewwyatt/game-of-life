let highest = (a, b) => a > b ? a : b;
let lowest = (a, b) => a > b ? b : a;
let eq = (a, b) => a === b;

let rec range = (start, end_) =>
  if (start >= end_) {
    [];
  } else {
    [start, ...range(start + 1, end_)];
  };