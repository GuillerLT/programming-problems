/* Problemset 803 - Problem B
 * https://codeforces.com/problemset/problem/803/B
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int const n = *istream_iterator<int>(cin);
  vector<int> vs;
  for (int i = 0; i < n; ++i) {
    if (*istream_iterator<int>(cin) == 0) {
      vs.push_back(i);
    }
  }
  vs.push_back(numeric_limits<int>::max());
  for (int i = 0; i < vs[0]; ++i) {
    cout << vs[0] - i << ' ';
  }
  for (int i = vs[0], r = 0; i < n; ++i) {
    if (i == vs[r]) {
      cout << "0 ";
      ++r;
    } else {
      cout << min(i - vs[r - 1], vs[r] - i) << ' ';
    }
  }
  cout << '\n';
  return 0;
}
