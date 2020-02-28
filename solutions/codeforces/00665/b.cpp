/* Problemset 665 - Problem B
 * https://codeforces.com/problemset/problem/665/B
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
  auto it = istream_iterator<int>(cin);
  int const nu = *it++;
  int const np = *it++;
  int const ni = *it++;
  array<int, 100> items;
  copy_n(it, ni, items.begin());
  int sol = np * nu;
  for (int u = 0; u < nu; ++u) {
    for (int p = 0; p < np; ++p) {
      int const i = *++it;
      auto f = find(items.begin(), items.begin() + ni, i);
      sol += f - items.begin();
      rotate(items.begin(), f, next(f));
    }
  }
  cout << sol << '\n';
  return 0;
}
