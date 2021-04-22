/* Problem hamming-distance
 * https://www.leetcode.com/problems/hamming-distance
 */

class Solution {
 public:
  int hammingDistance(int const x, int const y) {
    int ans{0};
    for (int z = x ^ y; z; z >>= 1) ans += (z & 1);
    return ans;
  }
};
