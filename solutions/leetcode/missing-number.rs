/* Problem missing-number
 * https://www.leetcode.com/problems/missing-number
 */

struct Solution;

impl Solution {
	pub fn missing_number(nums: Vec<i32>) -> i32 {
		let mut xor = nums.len();
		for (index, num) in nums.into_iter().enumerate() {
			xor ^= index ^ num as usize;
		}
		xor as i32
	}
}

fn main() {}
