/* Problemset 1189 - Problem A
 * https://codeforces.com/problemset/problem/1189/A
 */

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int z = 0, o = 0;
  for (char &c : s) {
    if (c == '0')
      ++z;
    else
      ++o;
  }
  if (z == o) {
    char const c = s.back();
    s.pop_back();
    cout << "2\n" << s << " " << c;
  } else {
    cout << "1\n" << s << "\n";
  }
}