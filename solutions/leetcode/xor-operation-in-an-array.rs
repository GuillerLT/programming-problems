/* Problem xor-operation-in-an-array
 * https://www.leetcode.com/problems/xor-operation-in-an-array
 */

impl Solution {
  pub fn xor_operation(n: i32, start: i32) -> i32 {
    let mut ans = 0;
    for i in 0..n {
      ans ^= start + 2 * i
    }
    ans
  }
}
