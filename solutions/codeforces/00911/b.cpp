/* Problemset 911 - Problem B
 * https://codeforces.com/problemset/problem/911/B
 */

#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  int const n = get<int>();
  auto const [a, b] = minmax({get<int>(), get<int>()});
  int sol = 0;
  for (int pa = 1; pa <= a && pa < n; ++pa) {
    int const pb = n - pa;
    if (pb <= b) {
      sol = max(sol, min(a / pa, b / pb));
    }
  }
  cout << sol << '\n';
  return 0;
}
