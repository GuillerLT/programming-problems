/* Problem running-sum-of-1d-array
 * https://www.leetcode.com/problems/running-sum-of-1d-array
 */

impl Solution {
  pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
    nums.iter()
        .scan(0, |acc, &num| { *acc += num; Some(*acc) })
        .collect()
  }
}
