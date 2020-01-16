/* Contest DEC19B - Problem WATSCORE
 * https://www.codechef.com/DEC19B/problems/WATSCORE
 */

#include <array>
#include <iostream>

using namespace std;

int main() {
  array<int, 12> ai;

  int t;
  cin >> t;
  while (--t >= 0) {
    ai.fill(0);
    int n;
    cin >> n;
    while (--n >= 0) {
      int i, v;
      cin >> i >> v;
      ai[i] = max(ai[i], v);
    }
    int sol = 0;
    for (int i = 1; i <= 8; ++i) {
      sol += ai[i];
    }
    cout << sol << '\n';
  }
  return 0;
}
