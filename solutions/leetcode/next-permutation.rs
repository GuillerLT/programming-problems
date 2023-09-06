/* Problem next-permutation
 * https://www.leetcode.com/problems/next-permutation
 */

struct Solution;

impl Solution {
	pub fn next_permutation(nums: &mut Vec<i32>) {
		let Some(a) = nums
			.windows(2)
			.enumerate()
			.rev()
			.find_map(|(i, w)| (w[0] < w[1]).then_some(i))
		else {
			nums.reverse();
			return;
		};

		let na = nums[a];

		let b = nums
			.iter()
			.copied()
			.enumerate()
			.rev()
			.find_map(|(i, n)| (n > na).then_some(i))
			.unwrap();

		nums.swap(a, b);
		nums[(a + 1)..].reverse();
	}
}

pub fn main() {}
