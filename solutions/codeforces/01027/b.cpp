/* Problemset 1027 - Problem B
 * https://codeforces.com/problemset/problem/1027/B
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
  long long const n = get<long long>(),
                  m = (n * n + 1) / 2;
  for (int q = get<int>(); q > 0; --q) {
    long long const x = get<long long>() - 1,
                    y = get<long long>() - 1,
                    cnt = (x * n + y) / 2 + 1;
    cout << cnt + ((x + y) % 2 == 0 ? 0 : m) <<'\n';
  }
  return 0;
}
