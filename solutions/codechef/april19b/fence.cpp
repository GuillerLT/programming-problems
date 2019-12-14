/* Contest APRIL19B - Problem FENCE
 * https://www.codechef.com/APRIL19B/problems/FENCE
 */

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    long long n, m, k;
    cin >> n >> m >> k;
    unordered_map<long long, bool> grid;
    int res = 4 * k;
    while (--k >= 0) {
      long long r, c;
      cin >> r >> c;
      --r;
      --c;
      grid[r * m + c] = true;
      if ((r - 1) >= 0 && grid[(r - 1) * m + c]) {
        res -= 2;
      }
      if ((c - 1) >= 0 && grid[r * m + (c - 1)]) {
        res -= 2;
      }
      if ((r + 1) < n && grid[(r + 1) * m + c]) {
        res -= 2;
      }
      if ((c + 1) < m && grid[r * m + (c + 1)]) {
        res -= 2;
      }
      // cout << res << "\n";
      // for (int i = 0; i < m; ++i) {
      //   for (int j = 0; j < n; ++j) {
      //     cout << grid[j * m + i] << " ";
      //   }
      //   cout << "\n";
      // }
    }
    cout << res << "\n";
  }
}