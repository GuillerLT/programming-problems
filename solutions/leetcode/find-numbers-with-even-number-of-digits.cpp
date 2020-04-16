/* Problem find-numbers-with-even-number-of-digits
 * https://www.leetcode.com/problems/find-numbers-with-even-number-of-digits
 */

#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int findNumbers(vector<int> const& nums) {
    return accumulate(nums.cbegin(), nums.cend(), 0, [](int const ans, int n) {
      int cnt = 0;
      for (; n; n /= 10) ++cnt;
      return ans + int{cnt != 0 && !(cnt & 1)};
    });
  }
};
