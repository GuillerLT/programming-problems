/* Problemset 598 - Problem A
 * https://codeforces.com/problemset/problem/598/A
 */

#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    long long n;
    cin >> n;
    long long a = n * (n + 1) / 2;
    for (long long p = 1; p <= n; p <<= 1) {
      a -= (p << 1);
    }
    cout << a << '\n';
  }
  return 0;
}