/* Problemset 1016 - Problem A
 * https://codeforces.com/problemset/problem/1016/A
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
  int const n = get<int>(), m = get<int>();
  for (int i = 0, cnt = 0; i < n; ++i, cnt %= m) {
    cnt += get<int>();
    cout << cnt / m << ' ';
  }
  cout << '\n';
  return 0;
}
