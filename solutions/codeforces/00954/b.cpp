/* Problemset 954 - Problem B
 * https://codeforces.com/problemset/problem/954/B
 */

#include <iostream>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  size_t const n = get<size_t>();
  string const s = get<string>();
  for (size_t d = n / 2; d > 0; --d) {
    if (equal(s.cbegin(), s.cbegin() + d, s.cbegin() + d)) {
      cout << n - d + 1 << '\n';
      return 0;
    }
  }
  cout << n << '\n';
  return 0;
}
