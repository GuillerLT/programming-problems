#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> vs;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    vs.emplace_back(move(s));
  }
  int counter = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vs[i][j] == 's') {
        if (j + 3 < m) {
          // R y
          if (vs[i][j + 1] == 'a' && vs[i][j + 2] == 'b' &&
              vs[i][j + 3] == 'a') {
            ++counter;
            // cout << "derecha" << "\n";
          }
          if (i + 3 < n) {
            // D y
            if (vs[i + 1][j] == 'a' && vs[i + 2][j] == 'b' &&
                vs[i + 3][j] == 'a') {
              ++counter;
              // cout << "abajo" << "\n";
            }
            if (vs[i + 1][j + 1] == 'a' && vs[i + 2][j + 2] == 'b' &&
                vs[i + 3][j + 3] == 'a') {
              ++counter;
              // cout << "derecha-abajo" << "\n";
            }
          }
          if (i - 3 >= 0) {
            // U y
            if (vs[i - 1][j + 1] == 'a' && vs[i - 2][j + 2] == 'b' &&
                vs[i - 3][j + 3] == 'a') {
              ++counter;
              // cout << "derecha-arriba" << "\n";
            }
          }
        } else if (i + 3 < n) {
          // R n D y
          if (vs[i + 1][j] == 'a' && vs[i + 2][j] == 'b' &&
              vs[i + 3][j] == 'a') {
            ++counter;
            // cout << "abajo" << "\n";
          }
        }
      }
    }
  }
  cout << counter << "\n";
  return 0;
}