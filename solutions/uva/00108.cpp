/* Problem 108
 * https://onlinejudge.org/external/1/108.pdf
 */

#include <array>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  array<array<int, 101>, 101> aai;
  for (int i = 0; i <= n; ++i) {
    aai[0][i] = 0;
    aai[i][0] = 0;
  }
  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c <= n; ++c) {
      cin >> aai[r][c];
      aai[r][c] += (aai[r - 1][c] + aai[r][c - 1] - aai[r - 1][c - 1]);
      // cout << aai[r][c] << '\t';
    }
    // cout << '\n';
  }
  int sol = aai[1][1];
  for (int rt = 1; rt <= n; ++rt) {
    for (int cl = 1; cl <= n; ++cl) {
      for (int rb = rt; rb <= n; ++rb) {
        for (int cr = cl; cr <= n; ++cr) {
          int const val = aai[rb][cr] - aai[rt - 1][cr] - aai[rb][cl - 1] +
                          aai[rt - 1][cl - 1];
          if (val >= sol) {
            // cout << rt << '-' << cl << ':' << rb << '-' << cr << '\n';
            sol = val;
          }
        }
      }
    }
  }
  cout << sol << '\n';
  return 0;
}