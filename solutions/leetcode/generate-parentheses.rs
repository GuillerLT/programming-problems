/* Problem generate-parentheses
 * https://www.leetcode.com/problems/generate-parentheses
 */

struct Solution;

impl Solution {
  pub fn generate_parenthesis(n: i32) -> Vec<String> {
    (0..n).fold(vec![(String::default(), 0)], |seqs_bals, _| {
      seqs_bals
      .into_iter()
      .flat_map(|(seq, bal)|{
        (0..=bal)
        .into_iter()
        .map(move |del| {
          (seq.clone() + ")".repeat(del).as_str() + "(", bal - del + 1)
        })
      }).collect()
    })
    .into_iter()
    .map(|(seq, bal)| {
      seq + ")".repeat(bal).as_str()
    }).collect()
  }
}

pub fn main() {
}
