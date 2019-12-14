/* Contest JUNE19B - Problem PROXYC
 * https://www.codechef.com/JUNE19B/problems/PROXYC
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    int n;
    cin >> n;
    int restantes = n * 3 / 4 + ((n * 3 % 4 == 0) ? 0 : 1);
    int proxy = 0;
    string s;
    cin >> s;
    int i = 0;
    for (; i < 2; ++i) {
      if (s[i] == 'P') {
        if (i + 1 >= 2 && s[i + 1] == 'A') {
          ++s[i + 1];
        }
        if (s[i + 2] == 'A') {
          ++s[i + 2];
        }
        --restantes;
      }
    }
    for (; i < n - 2; ++i) {
      if (s[i] == 'P') {
        if (s[i - 2] == 'B') {
          ++s[i - 2];
          ++proxy;
        }
        if (s[i - 1] == 'B') {
          ++s[i - 1];
          ++proxy;
        }
        if (s[i + 1] == 'A') {
          ++s[i + 1];
        }
        if (s[i + 2] == 'A') {
          ++s[i + 2];
        }
        --restantes;
      }
    }
    for (; i < n; ++i) {
      if (s[i] == 'P') {
        if (s[i - 2] == 'B') {
          ++s[i - 2];
          ++proxy;
        }
        if (i - 1 < n - 2 && s[i - 1] == 'B') {
          ++s[i - 1];
          ++proxy;
        }
        --restantes;
      }
    }
    // cout << restantes << "\n";
    // cout << s << "\n";
    if (restantes - proxy <= 0)
      cout << max(0, restantes) << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}