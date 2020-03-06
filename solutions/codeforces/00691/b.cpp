/* Problemset 691 - Problem B
 * https://codeforces.com/problemset/problem/691/B
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<char, char> mirror;
  string const s("AHIMOTUVWXYovwx");
  for (char const c : s) mirror[c] = c;
  mirror['p'] = 'q';
  mirror['q'] = 'p';
  mirror['d'] = 'b';
  mirror['b'] = 'd';
  string t;
  cin >> t;
  for (size_t i = 0; i < t.size() + 1 / 2; ++i) {
    if (mirror[t[i]] != t[t.size() - 1 - i]) {
      cout << "NIE\n";
      return 0;
    }
  }
  cout << "TAK\n";
  return 0;
}
