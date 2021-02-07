/* Problem factovisors
 * https://open.kattis.com/problems/factovisors
 */

#include <cstdio>

using namespace std;

void solve(int const n, int const m) {
  int mm = m;
  for (long long i = 2; i * i <= mm; ++i) {
    int exponent = 0;
    while (mm % i == 0) mm /= i, ++exponent;
    if (exponent > 0)
      for (int nn = n; nn >= i;) nn /= i, exponent -= nn;  // Legendre's Formula
    if (exponent > 0) mm = 0;
  }
  printf("%d %s %d!\n", m, (mm == 0 || mm > 1 && mm > n) ? "does not divide" : "divides", n);
}

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) == 2) solve(n, m);
  return 0;
}
