/* Contest JUNE17 - Problem XENRANK
 * https://www.codechef.com/JUNE17/problems/XENRANK
 */

#include <cstdio>

unsigned long long get() {
  unsigned long long ull;
  scanf("%llu", &ull);
  return ull;
}

int main() {
  for (unsigned long long t{get()}; t > 0; --t) {
    unsigned long long const u{get()};
    unsigned long long const v{get()};
    std::printf("%llu\n", ((u + v) * (u + v + 1) / 2 + u + 1));
  }
  return 0;
}