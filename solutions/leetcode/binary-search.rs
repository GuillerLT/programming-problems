/* Problem binary-search
 * https://www.leetcode.com/problems/binary-search
 */

struct Solution;

impl Solution {
	pub fn search(nums: Vec<i32>, target: i32) -> i32 {
		nums.binary_search(&target)
			.map(|i| i.try_into().unwrap())
			.unwrap_or(-1)
	}
}

pub fn main() {
	assert_eq!(4, Solution::search(vec![-1, 0, 3, 5, 9, 12], 9));
	assert_eq!(-1, Solution::search(vec![-1, 0, 3, 5, 9, 12], 2));
}
