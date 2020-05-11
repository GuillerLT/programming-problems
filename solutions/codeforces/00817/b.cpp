/* Problemset 817 - Problem B
 * https://codeforces.com/problemset/problem/817/B
 */

#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

int main() {
  map<int, int> m;
  for (int i = *istream_iterator<int>(cin); i > 0; --i) {
    ++m[*istream_iterator<int>(cin)];
  }
  int cnt = 3;
  for (auto it : m) {
    if (it.second < cnt) {
      cnt -= it.second;
    } else {
      unsigned long long n = it.second, d = 1;
      for (int i = 2; i <= cnt; ++i) {
        n *= (it.second - i + 1);
        d *= i;
      }
      cout << n / d << '\n';
      break;
    }
  }
  return 0;
}
