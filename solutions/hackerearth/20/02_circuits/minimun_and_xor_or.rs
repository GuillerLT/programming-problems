use std::io;
use std::cmp;

fn main() {
  let mut buffer = String::new();
  
  io::stdin().read_line(&mut buffer).unwrap();
  let t = buffer.trim().parse::<usize>().unwrap();
  
  for _ in 0..t {
    buffer.clear();
    io::stdin().read_line(&mut buffer).unwrap();
    let t = buffer.trim().parse::<usize>().unwrap();

    buffer.clear();
    io::stdin().read_line(&mut buffer).unwrap();
    let mut v = buffer.split_whitespace()
                  .map(|x| x.trim().parse::<i32>().unwrap())
                  .collect::<Vec<i32>>();
    v.sort();
    
    let mut min_op = v[0] ^ v[1];
    for i in 1..(t-1) {
      min_op = cmp::min(min_op, v[i] ^ v[i+1]);
    }
    println!("{}", min_op);
  }
}
