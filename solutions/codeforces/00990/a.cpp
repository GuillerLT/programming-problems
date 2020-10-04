/* Problemset 990 - Problem A
 * https://codeforces.com/problemset/problem/990/A
 */

#include <iostream>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  long long const n = get<long long>(), m = get<long long>(),
                  build = (m - n % m) * get<long long>(),
                  demolish =   n % m  * get<long long>();
  cout << min(build, demolish) << '\n';
  return 0;
}
