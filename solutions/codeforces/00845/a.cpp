/* Problemset 845 - Problem A
 * https://codeforces.com/problemset/problem/845/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  size_t const n = *istream_iterator<size_t>(cin);
  vector<int> v(2 * n);
  copy_n(istream_iterator<int>(cin), 2 * n, v.begin());
  sort(v.begin(), v.end());
  cout << ((v[n] > v[n - 1]) ? "YES\n" : "NO\n");
  return 0;
}
