/* Problemset 1 - Problem A
 * https://codeforces.com/problemset/problem/1/A
 */

#include <iostream>
using namespace std;

int main() {
  unsigned long long n, m, a;
  scanf("%llu%llu%llu", &n, &m, &a);
  unsigned long long w = n / a + (n % a > 0 ? 1 : 0);
  unsigned long long h = m / a + (m % a > 0 ? 1 : 0);
  unsigned long long sol = w * h;
  printf("%llu\n", sol);
  return 0;
}