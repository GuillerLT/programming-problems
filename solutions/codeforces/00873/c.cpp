/* Problemset 873 - Problem C
 * https://codeforces.com/problemset/problem/873/C
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n * m);
  copy_n(istream_iterator<int>(cin), n * m, v.begin());
  int sum_val = 0, sum_rep = 0;
  for (int col = 0; col < m; ++col) {
    int best_val = 0, best_rep = 0, cnt = 0;
    for (int row = 0; row < n; ++row) {
      if (v[row * m + col] == 1) {
        int val = 1;
        for (int row2 = min(row + k, n) - 1; row2 > row; --row2) {
          val += v[row2 * m + col];
        }
        if (val > best_val) {
          best_val = val;
          best_rep = cnt;
        }
        ++cnt;
      }
    }
    sum_val += best_val;
    sum_rep += best_rep;
  }
  cout << sum_val << ' ' << sum_rep << '\n';
}
