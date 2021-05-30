/* Problem maximum-product-of-word-lengths
 * https://www.leetcode.com/problems/maximum-product-of-word-lengths
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  static int maxProduct(std::vector<std::string> const& words) {
    std::vector<std::pair<std::size_t, std::bitset<26>>> data(words.size());
    std::transform(std::cbegin(words),
                   std::cend(words),
                   std::begin(data),
                   [](std::string const& word) {
                     return std::pair{word.size(),
                                      std::transform_reduce(
                                          std::cbegin(word),
                                          std::cend(word),
                                          std::bitset<26>{},
                                          std::bit_or{},
                                          [](char const c) {
                                            return std::bitset<26>{1ull << (c - 'a')};
                                          })};
                   });
    std::sort(std::begin(data),
              std::end(data),
              [](auto const a, auto const b) {
                return a.first < b.first;
              });
    std::size_t sol{0};
    auto const crend{std::crend(data)};
    for (auto ri{std::crbegin(data)}; ri != crend && ri->first * ri->first > sol; ri++) {
      for (auto rj{std::next(ri)}; rj != crend && ri->first * rj->first > sol; rj++) {
        if ((ri->second & rj->second).count() == 0) sol = ri->first * rj->first;
      }
    }
    return static_cast<int>(sol);
  }
};
