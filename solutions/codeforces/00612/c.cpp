/* Problemset 612 - Problem C
 * https://codeforces.com/problemset/problem/612/C
 */

#include <iostream>
#include <stack>

using namespace std;

int main() {
  string s;
  cin >> s;
  int changes = 0;
  stack<char> sc;
  for (char const c : s) {
    switch (c) {
      case '(':
      case '{':
      case '[':
      case '<':
        sc.push(c);
        break;
      case ')':
      case '}':
      case ']':
      case '>':
        if (sc.empty()) {
          cout << "Imposible\n";
          return 0;
        }
        if (abs(c - sc.top()) > 2) {
          ++changes;
        }
        sc.pop();
        break;
    }
  }
  if (!sc.empty()) {
    cout << "Impossible\n";
  } else {
    cout << changes << '\n';
  }
  return 0;
}
