/* Problemset 1360 - Problem C
 * https://codeforces.com/problemset/problem/1360/C
 */

#include <algorithm>
#include <array>
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
    array<size_t, 2> parity{0, 0};
    for (int &si : s) {
      si = get<int>();
      ++parity[si & 1];
    }
    if ((parity[0] & 1) == (parity[1] & 1)) {
      if ((parity[0] & 1) == 0) {
        cout << "YES\n";
      } else {
        sort(s.begin(), s.end());
        bool ok = false;
        for (size_t i = 1; i < n; ++i) {
          if (s[i] == s[i-1] + 1) {
            ok = true;
            break;
          }
        }
        cout << (ok ? "YES\n" : "NO\n");
      }
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
