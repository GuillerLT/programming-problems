/* Problemset 946 - Problem B
 * https://codeforces.com/problemset/problem/946/B
 */

use std::io;

fn foo(a: u64, b:u64) -> (u64, u64) {
  if a == 0 || b == 0 {
    (a, b)
  } else if a >= 2*b {
    foo(a % (2*b), b)
  } else if b >= 2*a {
    foo(a, b % (2*a))
  } else {
    (a, b)
  }
}

fn main() {
  let mut buffer = String::new();
  io::stdin().read_line(&mut buffer).unwrap();
  let data = buffer.split_whitespace()
                   .map(|x| x.trim().parse::<u64>().unwrap())
                   .collect::<Vec<u64>>();
  let (a,b) = foo(data[0], data[1]);
  println!("{} {}", a, b);
}
