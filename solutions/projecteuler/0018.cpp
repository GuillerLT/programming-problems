/* Problem 18
 * https://projecteuler.net/problem=18
 */

#include <algorithm>
#include <iostream>

using namespace std;

static constexpr size_t n = 15;

int main() {
  long long tri[n + 1][n + 1];
  fill(&tri[0][0], &tri[n][n], 0);
  for (int row = 1; row <= n; ++row) {
    for (int col = 1; col <= row; ++col) {
      cin >> tri[row][col];
      tri[row][col] += max(tri[row - 1][col - 1], tri[row - 1][col]);
      cout << tri[row][col] << ' ';
    }
    cout << '\n';
  }
  cout << *max_element(&tri[n][0], &tri[n][n]) << '\n';
  return 0;
}
