/* Problemset 888 - Problem A
 * https://codeforces.com/problemset/problem/888/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>

using namespace std;

int main() {
  size_t const n = *istream_iterator<size_t>(cin);
  unique_ptr<int[]> const a = make_unique<int[]>(n);
  copy_n(istream_iterator<int>(cin), n, a.get());
  size_t ans = 0;
  for (size_t i = 1; i + 1 < n; ++i) {
    ans += (a[i] > a[i - 1] && a[i] > a[i + 1]) |
           (a[i] < a[i - 1] && a[i] < a[i + 1]);
  }
  cout << ans << '\n';
  return 0;
}
