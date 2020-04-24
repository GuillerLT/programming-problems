/* Problem bitwise-and-of-numbers-range
 * https://www.leetcode.com/problems/bitwise-and-of-numbers-range
 */

class Solution {
 public:
  int rangeBitwiseAnd(int m, int const n) {
    bool aux = true;
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {
      int const x = m & (1 << i), y = n & (1 << i);
      aux &= (x == y);
      m &= ~(!aux << i);
    }
    return m;
  }
};
