/* Problemset 1476 - Problem A
 * https://codeforces.com/problemset/problem/1476/A
 */

#include <iostream>
#include <numeric>

using namespace std;

template <class T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t{get<int>()}; t > 0; --t) {
    int const n{get<int>()}, k1{get<int>()};
    long long const k{k1 * (1 + (n - 1) / k1)};
    cout << (1 + (k - 1) / n) << '\n';
  }
  return 0;
}
