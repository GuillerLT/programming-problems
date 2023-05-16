/* Problem move-zeroes
 * https://www.leetcode.com/problems/move-zeroes
 */

struct Solution;

impl Solution {
	pub fn move_zeroes(nums: &mut Vec<i32>) {
		let mut nz = 0;
		for i in 0..nums.len() {
			if nums[i] != 0 {
				nums.swap(i, nz);
				nz += 1;
			}
		}
	}
}

fn main() {}
