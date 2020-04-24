/* Problem subarray-sum-equals-k
 * https://www.leetcode.com/problems/subarray-sum-equals-k
 */

#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int> const& nums, int const k) {
    int ans = 0, pre = 0;
    map<int, int> f{{0, 1}};
    for (int const n : nums) {
      pre += n;
      ans += f[pre - k];
      ++f[pre];
    }
    return ans;
  }
};
