/* Problemset 266 - Problem A
 * https://codeforces.com/problemset/problem/266/A
 */

#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  string s;
  cin >> s;
  char lst = 0;
  int cnt = 0, max = 0;
  for (char const& c : s) {
    if (c == lst) {
      if (++cnt > max) max = cnt;
    } else {
      lst = c;
    }
  }
  cout << max << "\n";
  return 0;
}
