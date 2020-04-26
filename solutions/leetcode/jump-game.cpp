/* Problem jump-game
 * https://www.leetcode.com/problems/jump-game
 */

#include <vector>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int> const& nums) {
    int max_index = 0;
    for (int i = 0; i <= max_index && i < nums.size(); ++i) {
      max_index = max(max_index, i + nums[i]);
    }
    return max_index >= nums.size() - 1;
  }
};