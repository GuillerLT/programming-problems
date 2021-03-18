/* Problem wiggle-subsequence
 * https://www.leetcode.com/problems/wiggle-subsequence
 */

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    nums.push_back(nums.back());
    adjacent_difference(nums.cbegin(), nums.cend(), nums.begin());
    nums.front() = 0;
    size_t last_neg{0}, last_pos{0};
    for (size_t i = 1; i < nums.size(); ++i) {
      int& n = nums[i];
      if (n > 0) {
        n = nums[last_neg] + 1;
        last_pos = i;
      } else if (n < 0) {
        n = nums[last_pos] + 1;
        last_neg = i;
      }
    }
    return max(nums[last_neg], nums[last_pos]) + 1;
  }
};
