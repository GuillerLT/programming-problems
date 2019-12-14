/* Problem 12356
 * https://onlinejudge.org/external/123/12356.pdf
 */

#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int main() {
  while (true) {
    int b, s;
    cin >> b >> s;
    if (b == 0 && s == 0) return 0;
    set<tuple<int, int>> stii;
    stii.insert(make_tuple(1, b));
    for (int i = 0; i < s; ++i) {
      int l, r;
      cin >> l >> r;
      auto const& it = prev(stii.upper_bound(make_tuple(l, b + 1)));
      if (l == get<0>(*it)) {
        if (it == stii.cbegin()) {
          cout << "* ";
        } else {
          cout << get<1>(*prev(it)) << " ";
        }
      } else {
        cout << l - 1 << " ";
        stii.insert(it, make_tuple(get<0>(*it), l - 1));
      }
      if (r == get<1>(*it)) {
        if (next(it) == stii.cend()) {
          cout << "*\n";
        } else {
          cout << get<0>(*next(it)) << "\n";
        }
      } else {
        cout << r + 1 << "\n";
        stii.insert(it, make_tuple(r + 1, get<1>(*it)));
      }
      stii.erase(it);
    }
    cout << "-\n";
  }
}