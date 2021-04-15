/* Problem integer-replacement
 * https://www.leetcode.com/problems/integer-replacement
 */

class Solution {
 public:
  int integerReplacement(int n) {
    int ans{0};
    while (n > 1) {
      std::cout << n << '\n';
      ans += (1 << (n & 1));
      n = (n >> 1) + ((n & 3) == 3 && n != 3);
    }
    return ans;
  }
};
