/* Problemset 710 - Problem C
 * https://codeforces.com/problemset/problem/710/C
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<bool>> parity(n, vector<bool>(n, true));
  for (int i = 0; i < n; ++i) {
    parity[i][n / 2] = false;
    parity[n / 2][i] = false;
  }
  int rem = (n * n) / 2 - n / 2 * 4;
  for (int row = 0, col = 0; rem > 0; rem -= 4, ++row) {
    if (!parity[col][row]) {
      row = 0;
      ++col;
    }
    parity[col][row] = false;
    parity[n - col - 1][row] = false;
    parity[col][n - row - 1] = false;
    parity[n - col - 1][n - row - 1] = false;
  }
  int odd = -1, even = 0;
  for(int row = 0; row < n; ++row) {
    for(int col = 0; col < n; ++col) {
      cout << (parity[col][row] ? even += 2 : odd += 2) << ' ';
    }
    cout << '\n';
  }
  return 0;
}
