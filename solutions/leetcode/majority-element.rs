/* Problem majority-element
 * https://www.leetcode.com/problems/majority-element
 */

struct Solution;

impl Solution {
	pub fn majority_element(nums: Vec<i32>) -> i32 {
		nums.into_iter()
			.fold((0, 0), |(m, t), n| {
				if m == n {
					(m, t + 1)
				} else if t > 0 {
					(m, t - 1)
				} else {
					(n, 1)
				}
			})
			.0
	}
}

fn main() {}
