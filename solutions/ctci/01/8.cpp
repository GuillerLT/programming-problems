#include <concepts>
#include <vector>


// Time O ( n * m ) | Space O( 1 )
template <std::integral I>
void zero_matrix(std::vector<std::vector<I>> matrix) {
  for (std::size_t row{1}; row < matrix.size(); ++row) {
    for (std::size_t col{1}; col < matrix[row].size(); ++col) {
      if (matrix[row][col] == 0) matrix[row][0] = matrix[0][col] = 0;
    }
  }
  for (std::size_t row{0}; row < matrix.size(); ++row)
    if (matrix[row][0] == 0)
      for (std::size_t col{0}; col < matrix.front().size(); ++col)
        matrix[row][col] = 0;
  for (std::size_t col{0}; col < matrix.front().size(); ++col)
    if (matrix[0][col] == 0)
      for (std::size_t row{0}; row < matrix.size(); ++row)
        matrix[row][col] = 0;
}
