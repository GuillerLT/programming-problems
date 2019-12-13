/* Problemset 616 - Problem C
 * https://codeforces.com/problemset/problem/616/C
 */

#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

namespace glt {
template <typename T, std::size_t Dn, std::size_t... D>
class array : public array<std::array<T, Dn>, D...> {};
template <typename T, std::size_t Dn>
class array<T, Dn> : public std::array<T, Dn> {};
}  // namespace glt

int explore(glt::array<int, 1002, 1002>& ai, int const id, int const y,
            int const x) {
  if (ai[y][x] >= -1) {
    return 0;
  } else {
    ai[y][x] = id;
    return 1 + explore(ai, id, y + 1, x) + explore(ai, id, y - 1, x) +
           explore(ai, id, y, x + 1) + explore(ai, id, y, x - 1);
  }
}

int main() {
  glt::array<int, 1002, 1002> ai;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n + 1; ++i) {
    ai[i][0] = -1;
    ai[i][m + 1] = -1;
  }
  for (int j = 0; j <= m + 1; ++j) {
    ai[0][j] = -1;
    ai[n + 1][j] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      ai[i][j] = (c == '*') ? -1 : -2;
    }
  }
  vector<int> areas;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int const val = explore(ai, areas.size(), i, j);
      if (val > 0) areas.push_back(val);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (ai[i][j] == -1) {
        set<int> si;
        si.insert(ai[i + 1][j]);
        si.insert(ai[i - 1][j]);
        si.insert(ai[i][j + 1]);
        si.insert(ai[i][j - 1]);
        int val = 1;
        for (int const a : si) {
          if (a >= 0) val += areas[a];
        }
        cout << val % 10;
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }
  return 0;
}
