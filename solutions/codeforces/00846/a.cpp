/* Problemset 846 - Problem A
 * https://codeforces.com/problemset/problem/846/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <numeric>

using namespace std;

int main() {
  size_t const n = *istream_iterator<size_t>(cin);
  unique_ptr<int[]> const s{make_unique<int[]>(n)};
  copy_n(istream_iterator<int>(cin), n, s.get());
  int ans = 0, cnt_zeros = 0;
  for (size_t i = 0; i < n; ++i) {
    cnt_zeros += 1 - s[i];
    int cnt_ones = 0;
    for (size_t j = i; j < n; ++j) {
      cnt_ones += s[j];
    };
    ans = max(ans, cnt_zeros + cnt_ones);
  }
  cout << ans << '\n';
  return 0;
}
