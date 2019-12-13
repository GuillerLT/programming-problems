/* Problemset 620 - Problem A
 * https://codeforces.com/problemset/problem/620/A
 */

#include <iostream>

using namespace std;

int main() {
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << max(abs(x1 - x2), abs(y1 - y2)) << '\n';
  return 0;
}
