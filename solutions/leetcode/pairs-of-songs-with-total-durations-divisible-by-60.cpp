/* Problem pairs-of-songs-with-total-durations-divisible-by-60
 * https://www.leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60
 */

#include <algorithm>
#include <array>
#include <vector>

class Solution {
 public:
  unsigned long long numPairsDivisibleBy60(std::vector<int> times) {
    unsigned long long n_pairs{0};
    std::array<int, 60> freq_rem;
    freq_rem.fill(0);
    for (int const time : times) {
      int const rem{time % 60};
      n_pairs += freq_rem[(60 - rem) % 60];
      freq_rem[rem] += 1;
    }
    return n_pairs;
  }
};
