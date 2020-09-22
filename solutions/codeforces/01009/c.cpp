/* Problemset 1009 - Problem C
 * https://codeforces.com/problemset/problem/1009/C
 */

#include <iomanip>
#include <iostream>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  long long sum = 0;
  long long const n = get<long long>();
  long long const maxm = n * (n - 1) / 2LL, minm = n * n / 4LL;
  for (int m = get<int>(); m > 0; --m) {
    sum += get<long long>() * n;
    long long const d = get<long long>();
    if (d >= 0) {
      sum += d * maxm;
    } else {
      sum += d * minm;
    }
  }
  cout << setprecision(12) << static_cast<double>(sum) / n << '\n';
  return 0;
}
