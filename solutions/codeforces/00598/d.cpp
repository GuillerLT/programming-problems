#include <array>
#include <iostream>
#include <vector>

using namespace std;

int visit(int const y, int const x, int const i, int const j,
          array<array<bool, 1001>, 1001> const& walls,
          array<array<int, 1001>, 1001>& components, int const c) {
  if (i < 0 || i > y || j < 0 || j > x || components[i][j] >= 0) {
    return 0;
  } else if (walls[i][j]) {
    return 1;
  } else {
    components[i][j] = c;
    return visit(y, x, i, j + 1, walls, components, c) +
           visit(y, x, i, j - 1, walls, components, c) +
           visit(y, x, i + 1, j, walls, components, c) +
           visit(y, x, i - 1, j, walls, components, c);
  }
}

int main() {
  int y, x, q;
  cin >> y >> x >> q;
  array<array<bool, 1001>, 1001> walls;
  for (int i = 0; i < y; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < x; ++j) {
      walls[i][j] = (s[j] == '*');
    }
  }
  array<array<int, 1001>, 1001> components;
  for (auto& c : components) c.fill(-1);
  vector<int> sols;
  while (--q >= 0) {
    int i, j;
    cin >> i >> j;
    --i;
    --j;
    if (components[i][j] < 0) {
      sols.push_back(visit(y, x, i, j, walls, components, int(sols.size())));
    }
    cout << sols[components[i][j]] << '\n';
  }
  return 0;
}
