/* Problem container-with-most-water
 * https://www.leetcode.com/problems/container-with-most-water
 */

struct Solution;

impl Solution {
	pub fn max_area(height: Vec<i32>) -> i32 {
		let mut i = 0;
		let mut j = height.len() - 1;
		let mut max = 0;
		loop {
			if i >= j {
				break;
			}
			if height[i] < height[j] {
				max = max.max(height[i] * ((j - i) as i32));
				i += 1;
			} else {
				max = max.max(height[j] * ((j - i) as i32));
				j -= 1;
			}
		}
		max
	}
}

fn main() {}
