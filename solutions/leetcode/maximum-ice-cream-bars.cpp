/* Problem maximum-ice-cream-bars
 * https://www.leetcode.com/problems/maximum-ice-cream-bars
 */

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int maxIceCream(std::vector<int>& costs, int const coins) {
    std::sort(std::begin(costs), std::end(costs));
    std::vector<long long> costs_l(costs.size());
    std::transform_inclusive_scan(std::cbegin(costs), std::cend(costs),
                                  std::begin(costs_l),
                                  std::plus<long long>{},
                                  [](int const cost) { return static_cast<long long>(cost); });
    return std::distance(std::cbegin(costs_l),
                         std::upper_bound(std::cbegin(costs_l), std::cend(costs_l), coins));
  }
};
