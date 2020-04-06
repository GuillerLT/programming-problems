/* Problem best-time-to-buy-and-sell-stock-ii
 * https://www.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 */

use std::cmp;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        if prices.is_empty() {
            return 0;
        }
        let mut with_stock : i32 = -prices.first().unwrap();
        let mut without_stock : i32 = 0;
        for price in prices {
            with_stock = cmp::max(with_stock, without_stock - price);
            without_stock = cmp::max(without_stock, with_stock + price);
        }
        without_stock
    }
}
