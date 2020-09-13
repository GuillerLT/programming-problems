/* Problemset 976 - Problem B
 * https://codeforces.com/problemset/problem/976/B
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
  long long const rows = get<long long>(), cols = get<long long>(),
                  k = get<long long>();
  if (k < rows) {
    cout  << k + 1 << " 1\n";
  } else {
    long long const r = k - rows;
    long long const u = r / (cols - 1);
    cout << rows - u << ' ';
    long long const m = r % (cols - 1);
    if (u % 2 == 0) {
      cout << 2 + m << '\n';
    } else {
      cout << cols - m << '\n';
    }
  }
  return 0;
}
