/* Problem product-of-array-except-self
 * https://www.leetcode.com/problems/product-of-array-except-self
 */

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    size_t const n = nums.size();
    vector<int> pre(n + 1), su(n + 1);
    pre[0] = 1, su[n] = 1;
    for (int i = 0; i < n; ++i) {
      pre[i + 1] = pre[i] * nums[i];
      su[n - i - 1] = su[n - i] * nums[n - i - 1];
    }
    for (int i = 0; i < n; ++i) {
      nums[i] = pre[i] * su[i + 1];
    }
    return nums;
  }
};
