/* Problemset 1354 - Problem C2
 * https://codeforces.com/problemset/problem/1354/C2
 */

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

constexpr double const pi = 3.14159265358979323846;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (long long t = get<long long>(); t > 0; --t) {
    // Divisible by 2 but no by 4
    int const v = 2 * get<int>();
    cout << setprecision(20) << cos(pi / (2.0 * v)) / sin(pi / v) << '\n';
  }
  return 0;
}
