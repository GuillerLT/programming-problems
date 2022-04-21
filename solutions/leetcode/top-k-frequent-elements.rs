/* Problem top-k-frequent-elements
 * https://www.leetcode.com/problems/top-k-frequent-elements
 */

struct Solution;

impl Solution {
  pub fn top_k_frequent(mut nums: Vec<i32>, k: i32) -> Vec<i32> {
      nums.sort_unstable();
      let mut freqs = nums
        .into_iter()
        .fold(std::collections::HashMap::<i32, usize>::default(), |mut freqs, num| {
          *freqs.entry(num).or_default() += 1;
          freqs
        }).into_iter()
        .collect::<Vec<(i32, usize)>>();
      freqs.sort_unstable_by_key(|(_, freq)| *freq);
      freqs.iter().rev().take(k as usize).map(|(num, _)| *num).collect()
  }
}

pub fn main() {
}
