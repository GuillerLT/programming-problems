/* Problemset 1036 - Problem A
 * https://codeforces.com/problemset/problem/1036/A
 */

#include <iostream>

using namespace std;

template<typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  long long const b = get<long long>(),
                  a = get<long long>();
  cout << (a / b + !!(a % b)) << '\n';
  return 0;
}
