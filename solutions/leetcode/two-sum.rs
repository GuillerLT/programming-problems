/* Problem two-sum
 * https://www.leetcode.com/problems/two-sum
 */

struct Solution;

impl Solution {
	pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<usize> {
		let mut prev = std::collections::HashMap::new();
		for (i, num) in nums.into_iter().enumerate() {
			if let Some(j) = prev.get(&(target - num)) {
				return vec![*j, i];
			}
			prev.insert(num, i);
		}
		Vec::default()
	}
}

pub fn main() {}
