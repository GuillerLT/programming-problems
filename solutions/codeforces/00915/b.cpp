/* Problemset 915 - Problem B
 * https://codeforces.com/problemset/problem/915/B
 */

#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  int const            //
      n = get<int>(),  //
      p = get<int>(),  //
      l = get<int>(),  //
      r = get<int>();
  int ans = (l == 1 ? 0 : 1) + (r == n ? 0 : 1);
  if (p < l) {
    ans += l - p;
    if (r != n) ans += r - l;
  } else if (p > r) {
    ans += p - r;
    if (l != 1) ans += r - l;
  } else {
    if (l == 1) {
      if (r != n) {
        ans += r - p;
      }
    } else {
      if (r == n) {
        ans += p - l;
      } else {
        ans += 2 * min(r - p, p - l) + max(r - p, p - l);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
