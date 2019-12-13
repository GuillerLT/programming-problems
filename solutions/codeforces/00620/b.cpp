/* Problemset 620 - Problem B
 * https://codeforces.com/problemset/problem/620/B
 */

#include <array>
#include <iostream>

using namespace std;

int main() {
  array<int, 10> ai{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  int a, b;
  cin >> a >> b;
  long long sol = 0;
  for (int i = a; i <= b; ++i) {
    for (int j = i; j > 0; j /= 10) {
      sol += ai[j % 10];
    }
  }
  cout << sol << '\n';
  return 0;
}
