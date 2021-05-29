/* Problem rotate-image
 * https://www.leetcode.com/problems/rotate-image
 */

#include <vector>

class Solution {
 public:
  static void rotate(std::vector<std::vector<int>>& matrix) {
    std::size_t const n{matrix.size()};
    for (std::size_t i{0}; i < (n + 1) / 2; ++i) {
      for (std::size_t j{i + 1}; j < n - i; ++j) {
        std::exchange(matrix[i][j],
          std::exchange(matrix[n - 1 - j][i],
            std::exchange(matrix[n - 1 - i][n - 1 - j],
              std::exchange(matrix[j][n - 1 - i],
                matrix[i][j]))));
      }
    }
  }
};