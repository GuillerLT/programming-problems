/* Problem non-decreasing-array
 * https://www.leetcode.com/problems/non-decreasing-array
 */

#include <vector>

using namespace std;

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    bool error = false;
    if (nums.size() >= 2 && nums[0] > nums[1]) {
      error = true;
      nums[0] = nums[1];
    }
    for (size_t i = 1; i < nums.size() - 1; ++i) {
      if (nums[i] > nums[i + 1]) {
        if (error) return false;
        error = true;
        if (nums[i - 1] <= nums[i + 1]) {
          nums[i] = nums[i - 1];
        } else {
          nums[i + 1] = nums[i];
        }
      }
    }
    return true;
  }
};