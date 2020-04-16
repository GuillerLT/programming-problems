/* Problem subtract-the-product-and-sum-of-digits-of-an-integer
 * https://www.leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
 */

class Solution {
 public:
  int subtractProductAndSum(int n) {
    long long p = 1, s = 0;
    for (; n; n /= 10) {
      int const d = n % 10;
      p *= d;
      s += d;
    }
    return static_cast<int>(p - s);
  }
};
