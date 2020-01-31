/* Problemset 628 - Problem A
 * https://codeforces.com/problemset/problem/628/A
 */

#include <iostream>

using namespace std;

int main() {
  int n, b, p;
  cin >> n >> b >> p;
  cout << (n - 1) * (2 * b + 1) << ' ' << n * p << '\n';
  return 0;
}
