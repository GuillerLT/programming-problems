/* Problem majority-element
 * https://www.leetcode.com/problems/majority-element
 */

#include <numeric>
#include <utility>
#include <vector>

class Solution {
 public:
  int majorityElement(std::vector<int> const& nums) {
    return std::transform_reduce(
               std::cbegin(nums), std::cend(nums), std::pair{0, 0},
               [](std::pair<int, int> const p1, std::pair<int, int> const p2) {
                 if (p1.first == p2.first) {
                   return std::pair{p1.first, p1.second + p2.second};
                 } else {
                   if (p1.second > p2.second) {
                     return std::pair{p1.first, p1.second - p2.second};
                   } else {
                     return std::pair{p2.first, p2.second - p1.second};
                   }
                 }
               },
               [](int const n) { return std::pair{n, 1}; })
        .first;
  }
};
