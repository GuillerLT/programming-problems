/* Problemset 915 - Problem A
 * https://codeforces.com/problemset/problem/915/A
 */

use std::io;

fn main() {
  let mut buffer = String::new();
  io::stdin().read_line(&mut buffer).unwrap();
  let k = buffer.split_whitespace()
                .map(|x| x.trim().parse::<u8>().unwrap())
                .last()
                .unwrap();
  buffer.clear();
  io::stdin().read_line(&mut buffer).unwrap();
  let bucket = buffer.split_whitespace()
                     .map(|x| x.trim().parse::<u8>().unwrap())
                     .filter(|x| k % x == 0)
                     .max()
                     .unwrap();
  println!("{}", k / bucket);
}
