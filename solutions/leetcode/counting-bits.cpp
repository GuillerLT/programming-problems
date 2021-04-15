/* Problem counting-bits
 * https://www.leetcode.com/problems/counting-bits
 */

#include <vector>

class Solution {
 public:
  std::vector<int> countBits(int const num) {
    std::vector<int> ans(num + 1);
    ans.front() = 0;
    for (size_t i = 1; i <= num; ++i) ans[i] = ans[i >> 1] + (i & 1);
    return ans;
  }
};
