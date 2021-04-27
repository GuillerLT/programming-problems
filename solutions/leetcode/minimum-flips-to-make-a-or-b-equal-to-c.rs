/* Problem minimum-flips-to-make-a-or-b-equal-to-c
 * https://www.leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c
 */

impl Solution {
  pub fn min_flips(mut a: i32, mut b: i32, mut c: i32) -> i32 {
    let mut ans = 0;
    for _ in 0..32 {
      if (c & 1) == 1 {
        ans += 1 - ((a & 1) | (b & 1));
      } else {
        ans += (a & 1) + (b & 1);
      }
      a >>= 1;
      b >>= 1;
      c >>= 1;
    }
    ans
  }
}
