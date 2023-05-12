/* Problem best-time-to-buy-and-sell-stock
 * https://www.leetcode.com/problems/best-time-to-buy-and-sell-stock
 */

struct Solution;

impl Solution {
	pub fn max_profit(prices: Vec<i32>) -> i32 {
		prices
			.into_iter()
			.fold((0, i32::MAX), |(profit, min), price| {
				(i32::max(profit, price - min), i32::min(min, price))
			})
			.0
	}
}

pub fn main() {}
