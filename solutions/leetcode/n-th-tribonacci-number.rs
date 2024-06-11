/* Problem n-th-tribonacci-number
 * https://www.leetcode.com/problems/n-th-tribonacci-number
 */

impl Solution {
	pub fn tribonacci(n: i32) -> i32 {
		let n = n as usize;
		let mut vals = [0, 1, 1];
		for i in 3..=n {
			vals[i % 3] += vals[(i + 1) % 3];
			vals[i % 3] += vals[(i + 2) % 3];
		}
		return vals[n % 3];
	}
}

fn main() {
	assert_eq!(Solution::tribonacci(25), 1389537);
}

struct Solution;
