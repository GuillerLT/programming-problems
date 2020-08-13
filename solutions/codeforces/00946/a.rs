/* Problemset 946 - Problem A
 * https://codeforces.com/problemset/problem/946/A
 */

use std::io;

fn main() {
  let mut buffer = String::new();
  io::stdin().read_line(&mut buffer).unwrap();
  buffer.clear();
  io::stdin().read_line(&mut buffer).unwrap();
  let ans = buffer.split_whitespace()
                  .map(|x| i16::abs(x.trim().parse::<i16>().unwrap()))
                  .sum::<i16>();
  println!("{}", ans);
}
