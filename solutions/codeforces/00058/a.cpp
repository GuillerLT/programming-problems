/* Problemset 58 - Problem A
 * https://codeforces.com/problemset/problem/58/A
 */

#include <iostream>
using namespace std;

int main() {
  string s, h = "hello"s;
  cin >> s;
  int j = 0;
  for (int i = 0; i < s.length() && j < h.length(); ++i) {
    if (s[i] == h[j]) ++j;
  }
  if (j == h.length())
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
  return 0;
}