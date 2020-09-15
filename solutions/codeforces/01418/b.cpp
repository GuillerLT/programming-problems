/* Problemset 1418 - Problem B
 * https://codeforces.com/problemset/problem/1418/B
 */

#include <algorithm>
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
    vector<int> a(n), l(n), b;
    copy_n(istream_iterator<int>(cin), n, a.begin());
    copy_n(istream_iterator<int>(cin), n, l.begin());
    for (size_t i = 0; i < n; ++i) {
      if (l[i] == 0) {
        b.push_back(a[i]);
      }
    }
    sort(b.begin(), b.end());
    for (size_t i = 0, j = b.size(); i < n; ++i) {
      if (l[i] == 0) {
        a[i] = b[--j];
      }
    }
    copy(a.cbegin(), a.cend(), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
  return 0;
}
