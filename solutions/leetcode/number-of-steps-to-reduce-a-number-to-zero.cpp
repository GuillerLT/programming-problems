/* Problem number-of-steps-to-reduce-a-number-to-zero
 * https://www.leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero
 */

class Solution {
 public:
  int numberOfSteps(int num) {
    int cnt = 0;
    while (num) {
      int const aux{num & 1};
      num = (num - aux) >> (1 - aux);
      ++cnt;
    }
    return cnt;
  }
};
