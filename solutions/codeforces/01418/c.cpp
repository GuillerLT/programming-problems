/* Problemset 1418 - Problem C
 * https://codeforces.com/problemset/problem/1418/C
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t = get<int>(); t > 0; --t) {
    size_t const n = get<size_t>();
    vector<short> a(n);
    copy_n(istream_iterator<short>(cin), n, a.begin());
    array<int, 3> m, f;
    m[(n - 1) % 3] = 0;
    f[(n - 1) % 3] = a[n - 1];
    if (n > 1) {
      m[(n - 2) % 3] = 0;
      f[(n - 2) % 3] = a[n - 2];
    }
    for (int i = static_cast<int>(n) - 3; i >= 0; --i) {
      m[(i) % 3] = min(f[(i + 1) % 3], f[(i + 2) % 3]);
      f[(i) % 3] = a[i] + min(m[(i + 1) % 3], a[i + 1] + m[(i + 2) % 3]);
    }
    cout << f.front() << '\n';
  }
  return 0;
}
