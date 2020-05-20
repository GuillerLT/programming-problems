/* Problemset 1354 - Problem C1
 * https://codeforces.com/problemset/problem/1354/C1
 */

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (long long t = get<long long>(); t > 0; --t) {
    // Divisible by 2 and 4
    int const v = 2 * get<int>();
    cout << setprecision(20) <<  1.0 / tan(3.14159265358979323846 / v) << '\n';
  }
  return 0;
}
