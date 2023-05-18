/* Problem squares-of-a-sorted-array
 * https://www.leetcode.com/problems/squares-of-a-sorted-array
 */

struct Solution;

impl Solution {
	pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
		let mut r = match nums.binary_search(&0) {
			Ok(n) | Err(n) => n,
		};
		let mut l = r.wrapping_sub(1);
		let mut squares = Vec::new();
		loop {
			let v = if l > r && r == nums.len() {
				break squares;
			} else if r == nums.len() || (l < r && (-nums[l]) <= nums[r]) {
				let v = nums[l];
				l = l.wrapping_sub(1);
				v
			} else {
				let v = nums[r];
				r += 1;
				v
			};
			squares.push(v * v);
		}
	}
}

fn main() {
	dbg!(Solution::sorted_squares(vec![-4, -1, 0, 3, 10]));
}
