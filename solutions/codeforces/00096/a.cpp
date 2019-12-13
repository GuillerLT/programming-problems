/* Problemset 96 - Problem A
 * https://codeforces.com/problemset/problem/96/A
 */

#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int z = 0, o = 0;
  for (char const& c : s) {
    if (c == '0') {
      o = 0;
      if (++z >= 7) {
        cout << "YES"
             << "\n";
        return 0;
      };
    } else {
      z = 0;
      if (++o >= 7) {
        cout << "YES"
             << "\n";
        return 0;
      }
    }
  }
  cout << "NO"
       << "\n";
  return 0;
}
