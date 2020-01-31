/* Problemset 628 - Problem B
 * https://codeforces.com/problemset/problem/628/B
 */

#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  long long sol = 0;
  switch (s.front()) {
    case '0':
    case '4':
    case '8':
      sol = 1;
  }
  for (size_t i = 1; i < s.size(); ++i) {
    int8_t const n = (s[i - 1] - '0') * 10 + (s[i] - '0');
    if (n % 4 == 0) {
      sol += i;
    }
    switch (s[i]) {
      case '0':
      case '4':
      case '8':
        sol += 1;
    }
  }
  cout << sol << '\n';
  return 0;
}
