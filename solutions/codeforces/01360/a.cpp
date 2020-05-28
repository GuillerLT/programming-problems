/* Problemset 1360 - Problem A
 * https://codeforces.com/problemset/problem/1360/A
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
  for (int t = get<int>(); t > 0; --t) {
    int const a = get<int>(), b = get<int>();
    int const side = max(max(a, b), 2 * min(a, b));
    cout << side * side << '\n';
  }
  return 0;
}
