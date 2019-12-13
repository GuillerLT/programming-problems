/* Problemset 189 - Problem A
 * https://codeforces.com/problemset/problem/189/A
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  vector<int> c(3, 0);
  cin >> n >> c[0] >> c[1] >> c[2];
  vector<int> v(n + 1, 0);
  for (int j = 0; j < 3; ++j) {
    if (c[j] <= n) v[c[j]] = 1;
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      int const k = i - c[j];
      if (k >= 0 && v[k] > 0 && v[k] >= v[i]) {
        v[i] = v[k] + 1;
      }
    }
    // cout << v[i] << "\n";
  }
  cout << v.back() << "\n";
  return 0;
}
