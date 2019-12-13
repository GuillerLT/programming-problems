/* Problemset 612 - Problem A
 * https://codeforces.com/problemset/problem/612/A
 */

#include <iostream>

using namespace std;

int main() {
  int n, p, q;
  cin >> n >> p >> q;
  string s;
  cin >> s;
  if (q < p) swap(p, q);
  int a = -1, b;
  for (b = 0; a == -1; ++b) {
    if (n - b * q < 0) {
      break;
    } else if ((n - b * q) % p == 0) {
      a = (n - b * q) / p;
      break;
    }
  }
  if (a == -1) {
    cout << "-1\n";
  } else {
    cout << a + b << '\n';
    size_t i = 0;
    while (--a >= 0) {
      for (size_t j = 0; j < p; ++j) {
        cout << s[i++];
      }
      cout << '\n';
    }
    while (--b >= 0) {
      for (size_t j = 0; j < q; ++j) {
        cout << s[i++];
      }
      cout << '\n';
    }
  }
  return 0;
}
