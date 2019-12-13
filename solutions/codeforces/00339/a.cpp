/* Problemset 339 - Problem A
 * https://codeforces.com/problemset/problem/339/A
 */

#include <iostream>
#include <set>
using namespace std;

int main() {
  string s;
  cin >> s;
  multiset<char> sc;
  for (char const& c : s) {
    switch (c) {
      case '1':
      case '2':
      case '3':
        sc.insert(c);
    }
  }
  bool first = true;
  for (char const& c : sc) {
    if (first) {
      first = false;
    } else {
      cout << "+";
    }
    cout << c;
  }
  cout << "\n";
  return 0;
}