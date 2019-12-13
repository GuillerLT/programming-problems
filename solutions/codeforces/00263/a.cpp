/* Problemset 263 - Problem A
 * https://codeforces.com/problemset/problem/263/A
 */

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int y, x;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      int v;
      cin >> v;
      if (v) {
        y = i;
        x = j;
      }
    }
  }
  cout << abs(2 - y) + abs(2 - x) << "\n";
  return 0;
}