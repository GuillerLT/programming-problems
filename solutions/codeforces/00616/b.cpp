#include <iostream>
#include <limits>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int sol = numeric_limits<int>::min();
  for (int i = 1; i <= n; ++i) {
    int min_row = numeric_limits<int>::max();
    for (int j = 0; j < m; ++j) {
      int val;
      cin >> val;
      min_row = min(min_row, val);
    }
    sol = max(sol, min_row);
  }
  cout << sol << '\n';
  return 0;
}
