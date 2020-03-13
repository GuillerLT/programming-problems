/* Problemset 797 - Problem B
 * https://codeforces.com/problemset/problem/797/B
 */

#include <iostream>
#include <iterator>
#include <limits>

using namespace std;

int main() {
  long long ans = 0;
  int max_neg_odd = numeric_limits<int>::min(),
      min_pos_odd = numeric_limits<int>::max();
  int ok = 0;
  auto it = istream_iterator<int>(cin);
  for (int i = 0; i < *it; ++i) {
    int const v = *next(it);
    if (v > 0) {
      ok ^= v & 1;
      ans += v;
      if (v & 1) {
        min_pos_odd = min(min_pos_odd, v);
      }
    } else if (v & 1) {
      max_neg_odd = max(max_neg_odd, v);
    }
  }
  if (!ok) {
    if(-min_pos_odd < max_neg_odd) {
      ans += max_neg_odd;
    } else {
      ans -= min_pos_odd;
    }
  }
  cout << ans << '\n';
  return 0;
}
