/* Problemset 1354 - Problem B
 * https://codeforces.com/problemset/problem/1354/B
 */

#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  string s;
  for (long long t = get<long long>(); t > 0; --t) {
    s = get<string>();
    long long l1, l2, l3;
    l1 = l2 = l3 = s.size() + 1;
    long long ans = numeric_limits<long long>::max();
    for (char const c : s) {
      ++l1;
      ++l2;
      ++l3;
      switch (c) {
        case '1':
          l1 = 1;
          break;
        case '2':
          l2 = 1;
          break;
        case '3':
          l3 = 1;
          break;
      }
      ans = min(ans, max({l1, l2, l3}));
    }
    if ((size_t)ans > s.size()) ans = 0;
    cout << ans << '\n';
  }
  return 0;
}
