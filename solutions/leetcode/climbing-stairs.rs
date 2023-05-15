/* Problem climbing-stairs
 * https://www.leetcode.com/problems/climbing-stairs
 */

struct Solution;

impl Solution {
	pub fn climb_stairs(n: i32) -> i32 {
		let n = n as usize;
		let mut ways = [1, 2];
		for i in 2..n {
			ways[i % 2] += ways[(i + 1) % 2];
		}
		ways[(n + 1) % 2]
	}
}

fn main() {}
