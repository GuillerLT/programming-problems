/* Problem longest-common-subsequence
 * https://www.leetcode.com/problems/longest-common-subsequence
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string const& text1, string const& text2) {
    size_t const n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (size_t i = 0; i <= n; ++i) dp[i].front() = 0;
    for (size_t j = 0; j <= m; ++j) dp.front()[j] = 0;
    for (size_t i = 1; i <= n; ++i) {
      for (size_t j = 1; j <= m; ++j) {
        dp[i][j] = max({dp[i - 1][j],  //
                        dp[i][j - 1],  //
                        dp[i - 1][j - 1] + int{text1[i - 1] == text2[j - 1]}});
      }
    }
    return dp.back().back();
  }
};
