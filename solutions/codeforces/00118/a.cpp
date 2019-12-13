/* Problemset 118 - Problem A
 * https://codeforces.com/problemset/problem/118/A
 */

#include <iostream>
#include <string>
using namespace std;
int main() {
  string s, t;
  cin >> s;
  for (char& c : s) {
    if (c >= 'A' && c <= 'Z') c += ('a' - 'A');
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'y':
      case 'o':
      case 'u':
        break;
      default:
        t += "."s + c;
    }
  }
  cout << t << "\n";
}