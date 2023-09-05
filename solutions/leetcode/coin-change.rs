/* Problem coin-change
 * https://www.leetcode.com/problems/coin-change
 */

use std::vec;

struct Solution;

impl Solution {
	pub fn coin_change(coins: Vec<i32>, target: i32) -> i32 {
		let target: usize = target.try_into().unwrap();

		let coins = Vec::from_iter({
			let mut coins = coins;
			coins.sort();
			coins.dedup();
			coins.into_iter().map(|coin| coin.try_into().unwrap())
		});

		let mut mem = vec![i32::MAX - 1; target + 1];
		mem[0] = 0;
		for i in 1..=target {
			for coin in &coins {
				let Some(j) = usize::checked_sub(i, *coin) else {
					continue;
				};

				mem[i] = i32::min(mem[i], mem[j] + 1);
			}
		}

		let ans = *mem.last().unwrap();
		if ans == i32::MAX - 1 {
			-1
		} else {
			ans
		}
	}
}

pub fn main() {
	assert_eq!(3, Solution::coin_change(vec![1, 2, 5], 11));
	assert_eq!(-1, Solution::coin_change(vec![2], 3));
	assert_eq!(0, Solution::coin_change(vec![1], 0));
}
