/* Problemset 976 - Problem A
 * https://codeforces.com/problemset/problem/976/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  size_t const n = get<size_t>();
  size_t const m =
      count(istream_iterator<char>(cin), istream_iterator<char>(), '0');
  if (m != n) cout << '1';
  fill_n(ostream_iterator<char>(cout, ""), m, '0');
  cout << '\n';
  return 0;
}
