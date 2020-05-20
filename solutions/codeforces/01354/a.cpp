/* Problemset 1354 - Problem A
 * https://codeforces.com/problemset/problem/1354/A
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
  for (long long t = get<long long>(); t > 0; --t) {
    long long a = get<long long>();
    long long const b = get<long long>();
    long long const c = get<long long>();
    long long const d = get<long long>();
    if (b >= a) {
      cout << b;
    } else if (d >= c) {
      cout << -1;
    } else {
      long long const e = c - d;
      long long const rep = (a - b + e - 1) / e;
      cout << b + rep * c;
    }
    cout << '\n';
  }
  return 0;
}
