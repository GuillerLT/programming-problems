/* Problemset 863 - Problem A
 * https://codeforces.com/problemset/problem/863/A
 */

#include <iostream>
#include <iterator>

using namespace std;

int main() {
  string const s = *istream_iterator<string>(cin);
  bool ok = true;
  for (size_t i = 0, j = s.size() - 1; i < j;) {
    ok &= s[j] == '0';
    if (s[i] == s[j]) {
      ++i;
      --j;
    } else if (ok) {
      --j;
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
