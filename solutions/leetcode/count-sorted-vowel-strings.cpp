/* Problem count-sorted-vowel-strings
 * https://www.leetcode.com/problems/count-sorted-vowel-strings
 */

#include <array>

class Solution {
public:
    constexpr static int countVowelStrings(std::size_t const n) {
      std::array<int, 51 * 5> dp{};
      dp[0] = dp[51] = dp[102] = dp[153] = dp[204] = 1;
      for (std::size_t col = 1; col <= n; ++col) dp[col] = 1;

      for (std::size_t row = 1; row < 5; ++row) {
        for (std::size_t col = 1; col <= n; ++col) {
          for (std::size_t prow = 0; prow <= row; ++prow) {
            dp[row * 51 + col] += dp[prow * 51 + col - 1];
          }
        }
      }
      return dp[4 * 51 + n];
    }
};