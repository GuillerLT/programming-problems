/* Problem single-number-iii
 * https://www.leetcode.com/problems/single-number-iii
 */

#include <functional>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> singleNumber(std::vector<int> const& nums) {
    int const aux{std::reduce(std::cbegin(nums), std::cend(nums), 0, std::bit_xor{})};
    auto const ans{std::transform_reduce(
        std::cbegin(nums), std::cend(nums),
        std::pair{0, 0},
        [](std::pair<int, int> const p1, std::pair<int, int> const p2) {
          return std::pair{p1.first ^ p2.first, p1.second ^ p2.second};
        },
        [mask = static_cast<int>(aux & (~static_cast<unsigned int>(aux) + 1))](int const i) {
          return std::pair{i * !(i & mask), i * !!(i & mask)};
        })};
    return {ans.first, ans.second};
  }
};
