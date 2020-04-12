/* Problemset 817 - Problem A
 * https://codeforces.com/problemset/problem/817/A
 */

#include <iostream>

using namespace std;

int main() {
  int x1, y1, x2, y2, xt, yt;
  cin >> x1 >> y1 >> x2 >> y2 >> xt >> yt;
  int const xd = abs(x2 - x1), yd = abs(y2 - y1);
  int const xn = xd / xt, yn = yd / yt;
  if (xd % xt == 0 &&  //
      yd % yt == 0 &&  //
      (((xd / xt) & 1) == ((yd / yt) & 1))) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
