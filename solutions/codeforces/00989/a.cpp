/* Problemset 989 - Problem A
 * https://codeforces.com/problemset/problem/989/A
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
  string const s = get<string>();
  bool ans = false;
  for (size_t i = 1; i + 1 < s.size(); ++i) {
    ans |= s[i - 1] != s[i] && s[i] != s[i + 1] && s[i - 1] != s[i + 1] &&
           s[i - 1] != '.' && s[i] != '.' && s[i + 1] != '.';
  }
  cout << (ans ? "Yes\n" : "No\n");
  return 0;
}
