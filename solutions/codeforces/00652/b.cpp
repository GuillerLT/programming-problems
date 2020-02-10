/* Problemset 652 - Problem B
 * https://codeforces.com/problemset/problem/652/B
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  istream_iterator<int> isit(cin);
  int const n = *isit++;
  vector<int> vi;
  copy_n(isit, n, back_insert_iterator(vi));
  sort(vi.begin(), vi.end());
  for (auto it1 = vi.cbegin(), it2 = prev(vi.cend());; ++it1, --it2) {
    if (it1 >= it2) {
      if (it1 == it2) {
        cout << *it1 << ' ';
      }
      break;
    } else {
      cout << *it1 << ' ' << * it2 << ' ';
    }
  }
  cout << '\n';
  return 0;
}
