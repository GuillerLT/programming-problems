/* Problemset 813 - Problem A
 * https://codeforces.com/problemset/problem/813/A
 */

use std::io;

fn main() {
  let mut buffer = String::new();
  io::stdin().read_line(&mut buffer).unwrap();
  let n = buffer.trim().parse::<usize>().unwrap();

  buffer.clear();
  io::stdin().read_line(&mut buffer).unwrap();
  let mut v = buffer.split_whitespace()
                    .map(|x| x.trim().parse::<i32>().unwrap())
                    .collect::<Vec<i32>>();
  v.sort();

  buffer.clear();
  io::stdin().read_line(&mut buffer).unwrap();
  let m = buffer.trim().parse::<i32>().unwrap();
  let mut i = vec![-1];
  let mut e = vec![-1];
  
  for _ in 0..m {
    buffer.clear();
    io::stdin().read_line(&mut buffer).unwrap();
    let aux = buffer.split_whitespace()
                    .map(|x| x.trim().parse::<i32>().unwrap())
                    .collect::<Vec<i32>>();
    i.push(aux[0]);
    e.push(aux[1]);
  }
  
  let mut last = 0;
  let mut ok = m > 0;
  if ok {
    for j in 0..n {
      if  last + v[j] > e[e.len()-1] {
        ok =  false;
        break;
      }
      last += v[j];
    }
  }
  if ok {
    let index = 
    match i.binary_search(&last) {
      Ok(x)  => x,
      Err(x) => x,
    };
    if e[index-1] >= last {
      println!("{}", last);
    } else {
      println!("{}", i[index]);
    }
  } else {
    println!("-1");
  }
}
