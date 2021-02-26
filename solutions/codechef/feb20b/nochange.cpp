/* Contest FEB20B - Problem NOCHANGE
 * https://www.codechef.com/FEB20B/problems/NOCHANGE
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void sol(int const& p, vector<int> const& d) {
  for (size_t i = 0; i < d.size(); ++i) {
    if (p % d[i] != 0) {
      cout << "YES";
      for (size_t j = 0; j < i; ++j) cout << " 0";
      cout << ' ' << p / d[i] + 1;
      for (size_t j = i + 1; j < d.size(); ++j) cout << " 0";
      return;
    }
  }
  for (size_t i = 0; i < d.size(); ++i) {
    for (size_t j = i + 1; j < d.size(); ++j) {
      if (d[j] % d[i] != 0) {
        cout << "YES";
        for (size_t k = 0; k < i; ++k) cout << " 0";
        cout << ' ' << p / d[i] - (d[j] / d[i]);
        for (size_t k = i + 1; k < j; ++k) cout << " 0";
        cout << " 1";
        for (size_t k = j + 1; k < d.size(); ++k) cout << " 0";
        return;
      }
    }
  }
  cout << "NO";
}

int main() {
  auto it = istream_iterator<int>(cin);
  int t = *it;
  while (--t >= 0) {
    int const n = *++it;
    int const p = *++it;
    vector<int> d;
    copy_n(next(it), n, back_inserter(d));
    sol(p, d);
    cout << '\n';
  }
  return 0;
}
