/* Problemset 825 - Problem A
 * https://codeforces.com/problemset/problem/825/A
 */

#include <iostream>
#include <iterator>

using namespace std;

int main() {
  int const n = *istream_iterator<int>(cin);
  string const s = *istream_iterator<string>(cin);
  int cnt = 0;
  for (char const c : s) {
    if (c == '0') {
      cout << cnt;
      cnt = 0;
    } else {
      ++cnt;
    }
  }
  cout << cnt << '\n';
  return 0;
}
