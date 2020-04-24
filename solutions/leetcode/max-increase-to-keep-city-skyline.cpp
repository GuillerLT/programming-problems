/* Problem max-increase-to-keep-city-skyline
 * https://www.leetcode.com/problems/max-increase-to-keep-city-skyline
 */

#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> const& grid) {
    size_t const n = grid.size(), m = grid.front().size();
    vector<int> max_per_row(n, numeric_limits<int>::min()),
        max_per_col(m, numeric_limits<int>::min());
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        max_per_row[row] = max(max_per_row[row], grid[row][col]);
      }
    }
    for (int col = 0; col < m; ++col) {
      for (int row = 0; row < n; ++row) {
        max_per_col[col] = max(max_per_col[col], grid[row][col]);
      }
    }
    int ans = 0;
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        ans += min(max_per_row[row], max_per_col[col]) - grid[row][col];
      }
    }
    return ans;
  }
};