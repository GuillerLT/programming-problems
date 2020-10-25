/* Problemset 1036 - Problem B
 * https://codeforces.com/problemset/problem/1036/B
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
    long long const x = get<long long>(),
                    y = get<long long>(),
                    k = get<long long>(),
                    a = max(x, y),
                    b = min(x, y),
                    c = a - b,
                    d = k - a;
    if (k < a) {
      cout << "-1\n";
    } else {
      if (c % 2 == 0) {
        if (d % 2 == 0) {
          cout << k;
        } else {
          cout << k - 2;
        }
      } else {
        cout << k - 1;
      }
      cout << '\n';
    }
  }
  return 0;
}
