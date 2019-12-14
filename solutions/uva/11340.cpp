/* Problem 11340
 * https://onlinejudge.org/external/113/11340.pdf
 */

#include <cstdio>

#include <iostream>
using namespace std;

int main() {
  int t;
  scanf("%d\n", &t);
  while (--t >= 0) {
    long long prices[256];
    for (int i = 0; i < 256; ++i) prices[i] = 0LL;
    int n;
    scanf("%d\n", &n);
    while (--n >= 0) {
      unsigned char c;
      long long p;
      scanf("%c %lld\n", &c, &p);
      prices[c] = p;
    }
    scanf("%d\n", &n);
    long long total = 0LL;
    while (--n >= 0) {
      string l;
      getline(cin, l);
      for (unsigned char const& c : l) {
        total += prices[c];
      }
    }
    printf("%lld.%02lld$\n", total / 100, total % 100);
  }
  return 0;
}