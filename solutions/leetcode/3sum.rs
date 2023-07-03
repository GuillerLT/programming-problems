/* Problem 3sum
 * https://www.leetcode.com/problems/3sum
 */

struct Solution;

impl Solution {
	const TARGET: i32 = 0;

	pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
		let len = nums.len();
		nums.sort_unstable();
		let mut ans = Vec::new();
		for i in 0..(len - 2) {
			if i > 0 && nums[i] == nums[i - 1] {
				continue;
			}
			let target = Self::TARGET - nums[i];
			let mut left = i + 1;
			let mut right = len - 1;
			while left < right {
				let sum = nums[left] + nums[right];
				match sum.cmp(&target) {
					std::cmp::Ordering::Equal => {
						ans.push(vec![nums[i], nums[left], nums[right]]);
						left += 1;
						right -= 1;
						while left < right && nums[left] == nums[left - 1] {
							left += 1;
						}
					}
					std::cmp::Ordering::Less => {
						left += 1;
					}
					std::cmp::Ordering::Greater => {
						right -= 1;
					}
				}
			}
		}
		ans
	}
}

pub fn main() {}
