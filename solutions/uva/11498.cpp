/* Problem 11498
 * https://onlinejudge.org/external/114/11498.pdf
 */

#include <iostream>

using namespace std;

int main() {
  while (true) {
    int k;
    cin >> k;
    if (k == 0) break;
    int n, m;
    cin >> n >> m;
    while (--k >= 0) {
      int x, y;
      cin >> x >> y;
      if (x == n || y == m) {
        cout << "divisa";
      } else {
        cout << ((y > m) ? "N" : "S");
        cout << ((x > n) ? "E" : "O");
      }
      cout << "\n";
    }
  }
  return 0;
}