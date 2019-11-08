#include <array>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  array<char, 100002> rows, cols;
  while (--t >= 0) {
    int n, m, q;
    cin >> n >> m >> q;
    rows.fill((char)0);
    cols.fill((char)0);
    while (--q >= 0) {
      int r, c;
      cin >> r >> c;
      rows[r] ^= 1;
      cols[c] ^= 1;
    }
    long long r = 0, c = 0;
    for(int i=1; i<=n; ++i) {
        r += rows[i];
    }
    for(int i=1; i<=m; ++i) {
        c += cols[i];
    }
    cout << (r*m + c*n - 2*r*c) << '\n';
  }
  return 0;
}

