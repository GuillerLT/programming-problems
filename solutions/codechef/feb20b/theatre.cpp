/* Contest FEB20B - Problem THEATRE
 * https://www.codechef.com/FEB20B/problems/THEATRE
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <iterator>

using namespace std;

int main() {
  int t;
  cin >> t;
  int x = 0;
  while (t--) {
    array<array<int, 4>, 4> f;
    for (auto& g : f) g.fill(0);
    int n;
    cin >> n;
    while (n--) {
      char p;
      cin >> p;
      int h;
      cin >> h;
      ++f[p - 'A'][h / 3 - 1];
    }
    int b = -400;
    array<int, 4> o{0, 1, 2, 3};
    do {
      array<int, 4> s;
      for (int i = 0; i < 4; ++i) s[i] = f[o[i]][i];
      sort(s.begin(), s.end());
      int v = 0;
      array<int, 4> p{25, 50, 75, 100};
      for (int i = 0; i < 4; ++i) {
        if (s[i] == 0) {
          v -= 100;
        } else {
          v += s[i] * p[i];
        }
      }
      b = max(b, v);
    } while (next_permutation(o.begin(), o.end()));
    x += b;
    cout << b << '\n';
  }
  cout << x << '\n';
  return 0;
}
