/* Problem 10751
 * https://onlinejudge.org/external/107/10751.pdf
 */

#include <cstdio>
#include <string>
#include <cmath>
#include <type_traits>

template <class T>
T get(char const * const fmt) {
  T t;
  scanf(fmt, &t);
  return t;
}

int main() {
  double const sqrt2{sqrt(2.0)};
  for (int t{get<int>("%d")}; t > 0; --t) {
    int const n{get<int>("%d")};
    if (n == 1) {
      printf("0.000\n");
    } else  {
       int const diagonals{(n - 2) * (n - 2)};
       int const straights{n * n - diagonals};
       printf("%.3lf\n", straights + sqrt2 * diagonals);
    }
  }
  return 0;
}
