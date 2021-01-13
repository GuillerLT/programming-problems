/* Problemset 1073 - Problem A
 * https://codeforces.com/problemset/problem/1073/A
 */

#include <iostream>

using namespace std;

template <class T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  size_t const n{get<size_t>()};
  string const s{get<string>()};
  for (size_t i = 1; i < n; ++i) {
    if (s[i - 1] != s[i]) {
      cout << "YES\n" << s[i - 1] << s[i] << '\n';
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
