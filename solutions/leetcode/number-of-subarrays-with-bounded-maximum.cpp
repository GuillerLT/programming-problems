/* Problem number-of-subarrays-with-bounded-maximum
 * https://www.leetcode.com/problems/number-of-subarrays-with-bounded-maximum
 */

#include <utility>
#include <vector>

class Solution {
 public:
  int numSubarrayBoundedMax(std::vector<int> const& A, int const L, int const R) {
    int ans = 0;
    for (int i = 0, last_gR = -1, last_geL = -1; i < A.size(); ++i) {
      last_gR = (A[i] > R) ? i : last_gR;     // Last index whose value is greater than R
      last_geL = (A[i] >= L) ? i : last_geL;  // Last index whose value is greather or equal than L
      ans += std::max(0, last_geL - last_gR);
    }
    return ans;
  }
};
