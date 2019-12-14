/* Problem 10141
 * https://onlinejudge.org/external/101/10141.pdf
 */

#include <iostream>

using namespace std;

int main() {
  bool first = true;
  for (int i = 1;; ++i) {
    int n, p;
    cin >> n >> p;
    if (n == 0 && p == 0) break;
    if (!first) {
      cout << "\n";
    }
    first = false;
    while (n-- >= 0) {
      string s;
      getline(cin, s);
    }
    string bs;
    float bd;
    int br = -1;
    while (--p >= 0) {
      string s;
      getline(cin, s);
      float d;
      int r;
      cin >> d >> r;
      if (r > br || (r == br && d < bd)) {
        bs = s;
        bd = d;
        br = r;
      }
      while (r-- >= 0) {
        getline(cin, s);
      }
    }
    cout << "RFP #" << i << "\n" << bs << "\n";
  }
  return 0;
}