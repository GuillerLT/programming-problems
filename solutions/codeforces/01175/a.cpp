/* Problemset 1175 - Problem A
 * https://codeforces.com/problemset/problem/1175/A
 */

#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    long long n, k;
    cin >> n >> k;
    long long s = 0;
    while (n != 0) {
      long long const& r = n % k;
      if (r == 0) {
        n /= k;
        ++s;
      } else {
        n -= r;
        s += r;
      }
    }
    cout << s << "\n";
  }
}