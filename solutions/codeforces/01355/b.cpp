/* Problemset 1355 - Problem B
 * https://codeforces.com/problemset/problem/1355/B
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  auto it = istream_iterator<int>(cin);
  for (int t = *it; t > 0; --t) {
    size_t const n = *++it;
    vector<int> e(n);
    copy_n(++it, n, e.begin());
    sort(e.begin(), e.end());
    int ans = 0;
    for (size_t i = 0, j = 0; i < n && j < n;) {
      if (j - i + 1 >= (size_t)e[j]) {
        ++ans;
        j = i = j + 1;
      } else {
        j = i + e[j] - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
