/* Problemset 1473 - Problem A
 * https://codeforces.com/problemset/problem/1473/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <class T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t{get<int>()}; t > 0; --t) {
    int const n{get<int>()}, d{get<int>()};
    vector<int> a(n);
    copy_n(istream_iterator<int>(cin), n, a.begin());
    sort(a.begin(), a.end());
    cout << ((a[0] + a[1] <= d || a.back() <= d) ? "yes\n" : "no\n");
  }
  return 0;
}
