/* Problem sort-colors
 * https://www.leetcode.com/problems/sort-colors
 */

struct Solution;

impl Solution {
	pub fn sort_colors(nums: &mut Vec<i32>) {
		let mut f = [0usize; 3];
		for num in nums.iter() {
			f[*num as usize] += 1;
		}
		nums[0..f[0]].fill(0);
		nums[f[0]..f[1]].fill(1);
		nums[f[1]..f[2]].fill(2);
	}
}

pub fn main() {}
