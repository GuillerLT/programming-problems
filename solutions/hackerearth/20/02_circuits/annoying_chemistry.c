#include <stdio.h>

int main() {
  long long x, y, p, q;
  scanf("%Ld %Ld %Ld %Ld", &x, &y, &p, &q);
  // a*x = c*p
  // b*y = c*q
  long long a, b;
  for (long long c = 1;; ++c) {
    if (c * p % x == 0 && c * q % y == 0) {
      printf("%Ld %Ld %Ld\n", c * p / x, c * q / y, c);
      return 0;
    }
  }
}
