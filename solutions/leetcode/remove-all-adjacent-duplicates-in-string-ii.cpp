/* Problem remove-all-adjacent-duplicates-in-string-ii
 * https://www.leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii
 */

#include <functional>
#include <list>
#include <numeric>
#include <string>
#include <string_view>
#include <utility>

class Solution {
 public:
  std::string removeDuplicates(std::string_view const s, int const k) const {
    std::list<std::pair<char, int>> aux{{'A', 42}};
    for (char const c : s) {
      if (aux.back().first == c) {
        ++aux.back().second;
      } else {
        aux.emplace_back(c, 1);
      }
    }
    for (auto it = std::next(std::begin(aux)); it != std::cend(aux);) {
      if ((it->second %= k) == 0) {
        it = aux.erase(it);
        if (it != std::cend(aux) && it->first == std::prev(it)->first) {
          it->second += std::prev(it)->second;
          it = aux.erase(std::prev(it));
        }
      } else {
        ++it;
      }
    }
    return std::transform_reduce(
        std::next(std::cbegin(aux)), std::cend(aux),
        std::string{},
        std::plus{},  // UB: Not commutative
        [](std::pair<char, int> const l) { return std::string(l.second, l.first); });
  }
};
