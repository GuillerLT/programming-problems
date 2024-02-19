/* Problem partition-equal-subset-sum
 * https://www.leetcode.com/problems/partition-equal-subset-sum
 */

struct Solution;

impl Solution {
	pub fn can_partition(nums: Vec<i32>) -> bool {
		let target = {
			let sum = nums.iter().sum::<i32>();
			if sum % 2 == 1 {
				return false;
			}
			(sum / 2) as usize
		};

		let mut dp = vec![false; target + 1];
		dp[0] = true;

		for num in nums.into_iter().map(|num| num as usize) {
			for i in (num..=target).rev() {
				dp[i] = dp[i] || dp[i - num];
			}
		}

		dp[target]
	}
}

pub fn main() {
	let _ = Solution::can_partition(vec![1, 2, 5]);
}
