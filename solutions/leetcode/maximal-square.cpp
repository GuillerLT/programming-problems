/* Problem maximal-square
 * https://www.leetcode.com/problems/maximal-square
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int const n = matrix.size(), m = matrix.empty() ? 0 : matrix.front().size();
    vector<vector<int>> dp(n, vector<int>(m));
    int ans = 0;
    for (size_t i = 0; i < n; ++i)
      ans = max(ans, dp[i].front() = int{matrix[i].front() == '1'});
    for (size_t j = 0; j < m; ++j)
      ans = max(ans, dp.front()[j] = int{matrix.front()[j] == '1'});
    for (size_t i = 1; i < n; ++i) {
      for (size_t j = 1; j < m; ++j) {
        int const aux = int{matrix[i][j] == '1'};
        ans = max(ans, dp[i][j] = aux + aux * min({dp[i - 1][j], dp[i][j - 1],
                                                   dp[i - 1][j - 1]}));
      }
    }
    return ans * ans;
  }
};
