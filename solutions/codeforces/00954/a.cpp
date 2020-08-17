/* Problemset 954 - Problem A
 * https://codeforces.com/problemset/problem/954/A
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
  size_t m = 0;
  for (size_t i = 1; i < n; ++i) {
    if (s[i - 1] != s[i]) {
      ++m;
      ++i;
    }
  }
  cout << n - m << '\n';
  return 0;
}
