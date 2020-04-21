/* Problem minimum-path-sum
 * https://www.leetcode.com/problems/minimum-path-sum
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    size_t const n = grid.size(), m = grid.front().size();
    for (size_t j = 1; j < m; ++j) {
      grid.front()[j] += grid.front()[j - 1];
    }
    for (size_t i = 1; i < n; ++i) {
      grid[i].front() += grid[i - 1].front();
      for (size_t j = 1; j < m; ++j) {
        grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
      }
    }
    return grid.back().back();
  }
};
