/* Problemset 837 - Problem C
 * https://codeforces.com/problemset/problem/837/C
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  int sol = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j && (x[i] + x[j] <= a && y[i] <= b && y[j] <= b ||  //
                     x[i] + y[j] <= a && y[i] <= b && x[j] <= b ||  //
                     y[i] + x[j] <= a && x[i] <= b && y[j] <= b ||  //
                     y[i] + y[j] <= a && x[i] <= b && x[j] <= b ||  //
                     x[i] + x[j] <= b && y[i] <= a && y[j] <= a ||  //
                     x[i] + y[j] <= b && y[i] <= a && x[j] <= a ||  //
                     y[i] + x[j] <= b && x[i] <= a && y[j] <= a ||  //
                     y[i] + y[j] <= b && x[i] <= a && x[j] <= a)) {
        sol = max(sol, x[i] * y[i] + x[j] * y[j]);
      }
    }
  }
  cout << sol << '\n';
  return 0;
}
