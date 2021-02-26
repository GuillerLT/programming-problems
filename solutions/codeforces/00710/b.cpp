/* Problemset 710 - Problem B
 * https://codeforces.com/problemset/problem/710/B
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  size_t const n = *istream_iterator<size_t>(cin);
  vector<int> vi;
  copy_n(istream_iterator<int>(cin), n, back_inserter(vi));
  nth_element(vi.begin(), vi.begin() + (n - 1) / 2, vi.end());
  cout << vi[(n - 1) / 2] << '\n';
  return 0;
}
