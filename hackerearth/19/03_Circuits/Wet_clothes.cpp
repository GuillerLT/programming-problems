#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, g;
  cin >> n >> m >> g;
  int l;
  cin >> l;
  vector<int> rs;
  for (int i = 1; i < n; ++i) {
    int r;
    cin >> r;
    rs.push_back(r - l);
    l = r;
  }
  sort(rs.begin(), rs.end(), greater<int>());
  rs.resize(g);
  reverse(rs.begin(), rs.end());
  int d = 0;
  for (int i = 0; i < m; ++i) {
    int c;
    cin >> c;
    auto const it = upper_bound(rs.begin(), rs.end(), c);
    if (it != rs.end() || *(it - 1) == c) {
      ++d;
    }
  }
  cout << d << "\n";
}