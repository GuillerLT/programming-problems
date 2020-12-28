/* Problemset 1469 - Problem B
 * https://codeforces.com/problemset/problem/1469/B
 */

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t{get<int>()}; t > 0; --t) {
    vector<int> r(get<int>());
    copy_n(istream_iterator<int>(cin), r.size(), r.begin());
    inclusive_scan(r.cbegin(), r.cend(), r.begin(), plus<int>{});
    vector<int> b(get<int>());
    copy_n(istream_iterator<int>(cin), b.size(), b.begin());
    inclusive_scan(b.cbegin(), b.cend(), b.begin(), plus<int>{});
    cout << max(0, *max_element(r.cbegin(), r.cend())) + max(0, *max_element(b.cbegin(), b.cend())) << '\n';
  }
  return 0;
}
