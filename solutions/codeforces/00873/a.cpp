/* Problemset 873 - Problem A
 * https://codeforces.com/problemset/problem/873/A
 */

#include <iostream>
#include <iterator>
#include <limits>

using namespace std;

int main() {
  auto it = istream_iterator<int>(cin);
  int const n = *it;
  int const k = *++it;
  int const x = *++it;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += min(*++it, max(x, int{i + k < n} * numeric_limits<int>::max()));
  }
  cout << ans << '\n';
  return 0;
}
