/* Problem longest-increasing-subsequence
 * https://www.leetcode.com/problems/longest-increasing-subsequence
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <type_traits>
#include <vector>

template <class InputIt, class Compare>
constexpr size_t lenght_longest_sequence(InputIt first, InputIt const last,
                                         Compare comp = Compare{}) {
  using Type = std::iterator_traits<InputIt>::value_type;
  std::vector<Type> aux;
  for (; first != last; ++first) {
    auto const it = std::lower_bound(begin(aux), end(aux), *first, comp);
    if (it == cend(aux)) {
      aux.push_back(*first);
    } else {
      *it = *first;
    }
  }
  return aux.size();
}

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int> const& nums) {
    return lenght_longest_sequence(cbegin(nums), cend(nums), std::less<int>{});
  }
};
