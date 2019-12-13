/* Problemset 133 - Problem A
 * https://codeforces.com/problemset/problem/133/A
 */

#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (char const& c : s) {
    switch (c) {
      case 'H':
      case 'Q':
      case '9':
        cout << "YES";
        return 0;
    }
  }
  cout << "NO";
  return 0;
}