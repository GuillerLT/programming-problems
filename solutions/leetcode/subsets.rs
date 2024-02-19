/* Problem subsets
 * https://www.leetcode.com/problems/subsets
 */

struct Solution;

impl Solution {
	pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
		nums.into_iter().fold(vec![vec![]], |mut subsets, num| {
			for i in 0..subsets.len() {
				let mut subset = subsets[i].clone();
				subset.push(num);
				subsets.push(subset);
			}
			subsets
		})
	}
}

fn main() {}
