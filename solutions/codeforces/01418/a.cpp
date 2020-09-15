/* Problemset 1418 - Problem A
 * https://codeforces.com/problemset/problem/1418/A
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
    long long const x = get<long long>(), y = get<long long>(), k = get<long long>();
    long long const sticks = y * k + k - 1;
    cout << sticks / (x - 1) + (sticks % (x - 1) == 0 ? 0 : 1) + k << '\n';
  }
  return 0;
}
