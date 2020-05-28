/* Problemset 1360 - Problem B
 * https://codeforces.com/problemset/problem/1360/B
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t = get<int>(); t > 0; --t) {
    size_t const n = get<size_t>();
    vector<int> s(n);
    copy_n(istream_iterator<int>(cin), n, s.begin());
    sort(s.begin(), s.end());
    int ans = s[1] - s[0];
    for (size_t i = 2; i < n; ++i) {
      ans = min(ans, s[i] - s[i - 1]);
    }
    cout << ans << '\n';
  }
  return 0;
}
