/* Problemset 1476 - Problem B
 * https://codeforces.com/problemset/problem/1476/B
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>

using namespace std;

int geti() {
  int i;
  scanf("%d", &i);
  return i;
}

long long getlli() {
  long long lli;
  scanf("%lld", &lli);
  return lli;
}

int main() {
  for (int t{geti()}; t > 0; --t) {
    int n{geti()};
    int const k{geti()};
    long long m{getlli()};
    long long ans{0};
    while (--n) {
      long long const p{getlli()};
      long long const mr{1LL + (100LL * p - 1LL) / k};
      ans += max(m, mr) - m;
      m = max(m, mr) + p;
    }
    cout << ans << '\n';
  }
  return 0;
}
