/* Problemset 792 - Problem B
 * https://codeforces.com/problemset/problem/792/B
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>

using namespace std;

int main() {
  int const n = *istream_iterator<int>(cin), k = *istream_iterator<int>(cin);
  vector<int> vi(n);
  iota(vi.begin(), vi.end(), 1);
  for (int i = 0, l = 0; i < k; ++i) {
    size_t const s = n - i;
    l = (l + *istream_iterator<int>(cin)) % s;
    cout << vi[l] << ' ';
    rotate(vi.begin() + l, vi.begin() + l + 1, vi.begin() + s);
  }
  cout << '\n';
  return 0;
}
