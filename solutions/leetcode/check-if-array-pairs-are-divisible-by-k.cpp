/* Problem check-if-array-pairs-are-divisible-by-k
 * https://www.leetcode.com/problems/check-if-array-pairs-are-divisible-by-k
 */

#include <algorithm>
#include <vector>

class Solution {
 public:
  static bool canArrange(std::vector<int> const numbers, int const k) {
    std::vector<int> freqs_rem(k, 0);
    for (int const number : numbers) freqs_rem[(number % k + k) % k] += 1;
    for (int i{1}; i < (k + 1) / 2; ++i) {
      if (freqs_rem[i] != freqs_rem[k - i]) return false;
    }
    return !(freqs_rem.front() & 1);
  }
};
