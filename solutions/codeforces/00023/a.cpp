/* Problemset 23 - Problem A
 * https://codeforces.com/problemset/problem/23/A
 */

#include <array>
#include <iostream>

using namespace std;

int main() {
  array<int, 3001> pfactors;
  pfactors.fill(0);
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 2; i <= n; ++i) {
    if (pfactors[i] == 0) {
      for (int j = i + i; j <= n; j += i) {
        ++pfactors[j];
      }
    } else if (pfactors[i] == 2) {
      ++cnt;
    }
  }
  cout << cnt << "\n";
  return 0;
}