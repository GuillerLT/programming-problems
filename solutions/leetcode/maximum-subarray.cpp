/* Problem maximum-subarray
 * https://www.leetcode.com/problems/maximum-subarray
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sol = nums[0], par = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      par = max(par, 0) + nums[i];
      sol = max(sol, par);
    }
    return sol;
  }
};
