/* Problemset 710 - Problem A
 * https://codeforces.com/problemset/problem/710/A
 */

#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int sol = -1;
  for (char i = -1; i <= 1; ++i) {
    char const c = s.front() + i;
    for (char j = -1; j <= 1; ++j) {
      char const r = s.back() + j;
      sol += (c >= 'a' && c <= 'h' && r >= '1' && r <= '8');
    }
  }
  cout << sol << '\n';
  return 0;
}
