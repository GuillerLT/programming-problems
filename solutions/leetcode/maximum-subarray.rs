/* Problem maximum-subarray
 * https://www.leetcode.com/problems/maximum-subarray
 */

struct Solution;

impl Solution {
	pub fn max_sub_array(mut nums: Vec<i32>) -> i32 {
		let mut max = i32::MIN;
		let mut max_cur = 0;
		for num in nums {
			max_cur = i32::wrapping_add(i32::max(max_cur, 0), num);
			max = i32::max(max, max_cur);
		}
		max
	}
}

fn main() {}
