/* Problemset 990 - Problem B
 * https://codeforces.com/problemset/problem/990/B
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  vector<int> a(get<size_t>());
  int const k = get<int>();
  copy_n(istream_iterator<int>(cin), a.size(), a.begin());
  sort(a.begin(), a.end());
  adjacent_difference(a.cbegin(), a.cend(), a.begin());
  cout << accumulate(next(a.cbegin()), a.cend(), make_pair(a.size(), size_t{1}),
                 [k](pair<size_t, size_t> const r, int const ai) {
                   if (ai == 0) {
                     return make_pair(r.first, r.second + 1);
                   } else {
                     return make_pair(r.first - r.second * (ai <= k),
                                      size_t{1});
                   }
                 })
              .first
       << '\n';
  return 0;
}
