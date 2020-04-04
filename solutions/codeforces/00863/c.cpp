/* Problemset 863 - Problem C
 * https://codeforces.com/problemset/problem/863/C
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main() {
  long long int k;
  int a, b;
  cin >> k >> a >> b;
  array<array<array<int, 3>, 3>, 2> ai;
  copy_n(istream_iterator<int>(cin), 3 * 3 * 2, &ai[0][0][0]);
  long long pa = 0, pb = 0;
  map<pair<int, int>, tuple<long long, long long, long long>> mpt;
  auto it = mpt.cbegin();
  for (long long l = 0; l < k; ++l) {
    if ((it = mpt.find(make_pair(a, b))) != mpt.cend()) {
      long long const rep = (k - l) / (l - get<0>(it->second));
      pa += rep * (pa - get<1>(it->second));
      pb += rep * (pb - get<2>(it->second));
      l += rep * (l - get<0>(it->second)) - 1;
      mpt.clear();
    } else {
      mpt[make_pair(a, b)] = make_tuple(l, pa, pb);
      pa += a == b % 3 + 1;
      pb += b == a % 3 + 1;
      int const na = ai[0][a - 1][b - 1];
      int const nb = ai[1][a - 1][b - 1];
      a = na;
      b = nb;
    }
  }
  cout << pa << ' ' << pb << '\n';
}
