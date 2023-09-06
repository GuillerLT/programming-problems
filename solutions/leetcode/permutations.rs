/* Problem permutations
 * https://www.leetcode.com/problems/permutations
 */

struct Solution;

impl Solution {
	pub fn permute(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
		nums.sort_unstable();

		let mut permutations = Vec::with_capacity((1..=nums.len()).product());

		loop {
			permutations.push(nums.clone());

			let Some(a) = nums
				.windows(2)
				.enumerate()
				.rev()
				.find_map(|(i, w)| (w[0] < w[1]).then_some(i))
			else {
				break permutations;
			};

			let na = nums[a];

			let b = nums
				.iter()
				.enumerate()
				.rev()
				.find_map(|(i, n)| (*n > na).then_some(i))
				.unwrap();

			nums.swap(a, b);
			nums[(a + 1)..].reverse();
		}
	}
}

pub fn main() {
	assert_eq!(
		vec![
			vec![1, 2, 3],
			vec![1, 3, 2],
			vec![2, 1, 3],
			vec![2, 3, 1],
			vec![3, 1, 2],
			vec![3, 2, 1]
		],
		Solution::permute(vec![1, 2, 3])
	);
}
