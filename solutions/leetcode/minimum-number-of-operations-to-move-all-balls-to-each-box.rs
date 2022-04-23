/* Problem minimum-number-of-operations-to-move-all-balls-to-each-box
 * https://www.leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
 */

struct Solution;

impl Solution {
  pub fn min_operations(boxes: String) -> Vec<i32> {
      let partial_dist = |(dist, balls): &mut (i32, i32), current: char| {
        *dist += *balls;
        *balls += (current == '1') as i32;
        Some(*dist)
      };
      let f = boxes.chars().scan((0, 0), partial_dist).collect::<Vec<i32>>();
      let b = boxes.chars().rev().scan((0, 0), partial_dist).collect::<Vec<i32>>();
      println!("{:?}", f);
      println!("{:?}", b);
      f.iter().zip(b.iter().rev()).map(|(f, b)| {
        f + b
      }).collect()
  }
}

pub fn main() {
}
