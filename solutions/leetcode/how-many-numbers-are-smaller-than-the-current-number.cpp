/* Problem how-many-numbers-are-smaller-than-the-current-number
 * https://www.leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number
 */

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> f(accumulate(nums.cbegin(), nums.cend(), vector<int>(102, 0),
                             [](vector<int>& f, int const n) {
                               ++f[n + 1];
                               return f;
                             }));
    partial_sum(f.cbegin(), f.cend(), f.begin());
    transform(nums.cbegin(), nums.cend(), nums.begin(),
              [&f](int const n) { return f[n]; });
    return nums;
  }
};
