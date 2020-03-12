/* Problemset 792 - Problem A
 * https://codeforces.com/problemset/problem/792/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int const n = *istream_iterator<int>(cin);
  vector<int> vi;
  copy_n(istream_iterator<int>(cin), n, back_insert_iterator<vector<int>>(vi));
  sort(vi.begin(), vi.end());
  int prev = vi.front(), d = numeric_limits<int>::max(), cnt = 0;
  for_each(next(vi.cbegin()), vi.cend(), [&prev, &d, &cnt](int const next) {
    int const nd = next - prev;
    if (nd < d) {
      d = nd;
      cnt = 1;
    } else if (nd == d) {
      ++cnt;
    }
    prev = next;
  });
  cout << d << ' ' << cnt << '\n';
}
