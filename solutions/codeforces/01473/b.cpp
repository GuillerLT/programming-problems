/* Problemset 1473 - Problem B
 * https://codeforces.com/problemset/problem/1473/B
 */

#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

template <class T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t{get<int>()}; t > 0; --t) {
    string const a{get<string>()}, b{get<string>()};
    size_t const c{lcm(a.size(), b.size())};
    bool f = false;
    for (int i = 1; i <= 20; ++i) {
      size_t const l{i * c};
      bool ok = true;
      for (size_t j = 0; j < l; ++j) {
        ok &= a[j % a.size()] == b[j % b.size()];
      }
      if ((f = ok)) {
        for (size_t j = 0; j < l; ++j) {
          cout << a[j % a.size()];
        }
        break;
      }
    }
    if (!f) {
      cout << "-1";
    }
    cout << '\n';
  }
  return 0;
}
