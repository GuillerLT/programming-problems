/* Problemset 818 - Problem A
 * https://codeforces.com/problemset/problem/818/A
 */

use std::io;

fn main() {
  let mut buffer = String::new();
  io::stdin().read_line(&mut buffer).unwrap();
  let input = buffer.split_whitespace()
                    .map(|x| x.trim().parse::<i64>().unwrap())
                    .collect::<Vec<i64>>();
  let n = input[0];
  let k = input[1];
  let d = (n / 2) / (k + 1);
  let c = d * k;
  let o = n - d - c;
  println!("{} {} {}", d, c, o);
}
