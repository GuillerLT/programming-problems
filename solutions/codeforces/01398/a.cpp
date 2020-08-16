/* Problemset 1398 - Problem A
 * https://codeforces.com/problemset/problem/1398/A
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
  for (int t = get<int>(); t--;) {
    vector<int> a(get<size_t>());
    copy_n(istream_iterator<int>(cin), a.size(), a.begin());
    if (a[0] + a[1] <= a.back()) {
      cout << "1 2 " << a.size() << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
