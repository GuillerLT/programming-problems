/* Problem combination-sum
 * https://www.leetcode.com/problems/combination-sum
 */

use std::vec;

struct Solution;

impl Solution {
	pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
		let target: usize = target.try_into().unwrap();
		let candidates: Vec<usize> = candidates
			.into_iter()
			.map(|candidate| candidate.try_into().unwrap())
			.collect();

		let mut combinations: Vec<Vec<Vec<usize>>> = vec![vec![]; target + 1];
		combinations[0].push(vec![]);
		for target in 1..=target {
			for candidate in &candidates {
				let Some(prev) = usize::checked_sub(target, *candidate) else {
					continue;
				};
				for mut combination in combinations[prev].clone() {
					if *candidate < combination.last().copied().unwrap_or(0) {
						continue;
					}

					combination.push(*candidate);
					combinations[target].push(combination);
				}
			}
		}

		combinations
			.pop()
			.unwrap()
			.into_iter()
			.map(|combination| {
				combination
					.into_iter()
					.map(|candidate| candidate.try_into().unwrap())
					.collect()
			})
			.collect()
	}
}

pub fn main() {}
