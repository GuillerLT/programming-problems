use std::io;
use std::collections::HashSet;
use std::cmp;

fn main() {
  let mut buffer = String::new();
  
  io::stdin().read_line(&mut buffer).unwrap();
  let n = buffer.trim().parse::<usize>().unwrap();
  let mut handshakes = n * (n-1) / 2;
  
  let mut hate = HashSet::<i64>::new();
  
  for _ in 0..10 {
    buffer.clear();
    io::stdin().read_line(&mut buffer).unwrap();
    let v = buffer.split_whitespace()
                    .map(|x| x.trim().parse::<i64>().unwrap())
                    .collect::<Vec<i64>>();
    for i in 1..10 {
      let i = (cmp::max(v[0], v[i]) << 32) | cmp::min(v[0], v[i]);
      if hate.insert(i) {
        handshakes -= 1;
      }
    }
  }
  
  println!("{}", handshakes);
}
