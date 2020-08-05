/* Problemset 903 - Problem A
 * https://codeforces.com/problemset/problem/903/A
 */

use std::io;

fn main() {
  let mut buffer = String::new();
  io::stdin().read_line(&mut buffer).unwrap();
  let n = buffer.trim().parse::<usize>().unwrap();
  for _ in 0..n {
    buffer.clear();
    io::stdin().read_line(&mut buffer).unwrap();
    let x = buffer.trim().parse::<u8>().unwrap();
    let mut ok = false;
    for a in 0..34 {
      for b in 0..15 {
        ok |= (a *  3 + b * 7) == x;
      }
    }
    if ok {
      println!("YES");
    } else {
      println!("NO");
    }
  }
}
