/* Problem richest-customer-wealth
 * https://www.leetcode.com/problems/richest-customer-wealth
 */

impl Solution {
  pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
    accounts.iter()
            .map(|account| account.iter().sum())
            .max()
            .unwrap()
  }
}
