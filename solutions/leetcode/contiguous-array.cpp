/* Problem contiguous-array
 * https://www.leetcode.com/problems/contiguous-array
 */

#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int> const& nums) {
    int ans = 0;
    map<int, int> m{{0, -1}};
    for (int i = 0, cnt = 0; i < nums.size(); ++i) {
      cnt += nums[i] * 2 - 1;
      ans = max(ans, i - m.insert({cnt, i}).first->second);
    }
    return ans;
  }
};
