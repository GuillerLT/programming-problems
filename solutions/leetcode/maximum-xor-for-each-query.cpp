/* Problem maximum-xor-for-each-query
 * https://www.leetcode.com/problems/maximum-xor-for-each-query
 */

#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> getMaximumXor(std::vector<int>& nums, int const maximumBit) {
    int const mask{(1 << maximumBit) - 1};
    std::inclusive_scan(std::cbegin(nums), std::cend(nums), std::begin(nums),
                        std::bit_xor{});
    std::transform(std::cbegin(nums), std::cend(nums), std::begin(nums),
                   [mask](int const n) { return ~n & mask; });
    return std::vector<int>{std::crbegin(nums), std::crend(nums)};
  }
};
