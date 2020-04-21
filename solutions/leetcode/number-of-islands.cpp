/* Problem number-of-islands
 * https://www.leetcode.com/problems/number-of-islands
 */

#include <vector>

using namespace std;

class Solution {
 private:
  int visit(vector<vector<char>>& grid, int const i, int const j) {
    if (i >= 0 && i < grid.size() &&     //
        j >= 0 && j < grid[i].size() &&  //
        grid[i][j] == '1') {
      grid[i][j] = '0';
      visit(grid, i + 1, j);
      visit(grid, i - 1, j);
      visit(grid, i, j + 1);
      visit(grid, i, j - 1);
      return 1;
    } else {
      return 0;
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    for (int i = grid.size(); i > 0; --i) {
      for (int j = grid[i - 1].size(); j > 0; --j) {
        ans += visit(grid, i - 1, j - 1);
      }
    }
    return ans;
  }
};
