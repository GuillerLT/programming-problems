/* Problem number-of-good-ways-to-split-a-string
 * https://www.leetcode.com/problems/number-of-good-ways-to-split-a-string
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  int numSplits(std::string const& s) {
    using char_set_t = std::bitset<'z' - 'a' + 1>;
    std::vector<char_set_t> char_sets_lr(s.size()), char_sets_rl(s.size());
    auto const to_bitset{[](char const c) { return char_set_t{1 << (c - 'a')}; }};
    std::transform_inclusive_scan(std::cbegin(s), std::cend(s), std::begin(char_sets_lr), std::bit_or{}, to_bitset);
    std::transform_inclusive_scan(std::crbegin(s), std::crend(s), std::rbegin(char_sets_rl), std::bit_or{}, to_bitset);
    return std::inner_product(std::next(std::cbegin(char_sets_rl)), std::cend(char_sets_rl), std::cbegin(char_sets_lr),
                              0ULL, std::plus{}, [](char_set_t const char_set1, char_set_t const char_set2) { return char_set1.count() == char_set2.count(); });
  }
};
