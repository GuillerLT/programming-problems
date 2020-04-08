/* Problem single-number
 * https://www.leetcode.com/problems/single-number
 */

#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    return accumulate(nums.cbegin(), nums.cend(), 0,
                      [](int const x, int const y) { return x ^ y; });
  }
};
