/* Problemset 813 - Problem B
 * https://codeforces.com/problemset/problem/813/B
 */

use std::io;
use std::cmp;

fn main() {
  let mut buffer = String::new();
  io::stdin().read_line(&mut buffer).unwrap();
  let input : Vec<i64> = buffer.split_whitespace()
                                 .map(|x| x.trim().parse::<i64>().unwrap())
                                 .collect();
  let x = input[0];
  let y = input[1];
  let l = input[2];
  let r = input[3];
  
  let mut powx: Vec<i64> = vec![1];
  while r / powx.last().unwrap() >= x {
    powx.push(powx.last().unwrap() * x);
  }
  
  let mut powy: Vec<i64> = vec![1];
  while r / powy.last().unwrap() >= y {
    powy.push(powy.last().unwrap() * y);
  }
  
  let mut unluckys : Vec<i64> = vec![l-1, r+1];
  for i in &powx {
    for j in &powy {
      if i + j >= l && i + j <= r {
        unluckys.push(i+j);
      }
    }
  }
  unluckys.sort();

  let mut max_lucky : i64 = 0;
  for i in 1..unluckys.len() {
    max_lucky = cmp::max(max_lucky, unluckys[i] - unluckys[i-1]);
  }
  println!("{}", max_lucky-1);
}
