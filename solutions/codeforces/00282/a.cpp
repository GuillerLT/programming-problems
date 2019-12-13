/* Problemset 282 - Problem A
 * https://codeforces.com/problemset/problem/282/A
 */

#include <iostream>
using namespace std;

int main() {
  int n, m = 0;
  cin >> n;
  while (--n >= 0) {
    string s;
    cin >> s;
    for (char const& c : s) {
      if (c == '+') {
        ++m;
        break;
      } else if (c == '-') {
        --m;
        break;
      }
    }
  }
  cout << m << "\n";
}