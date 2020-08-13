/* Problemset 938 - Problem B
 * https://codeforces.com/problemset/problem/938/B
 */

#include <iostream>
#include <utility>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  int ans = 0;
  for (int n = get<int>(); n--;) {
    int const ai = get<int>();
    ans = max(ans, min(ai, 1000001 - ai));
  }
  cout << ans - 1 << '\n';
  return 0;
}
