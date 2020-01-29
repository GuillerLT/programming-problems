/* Problemset 817 - Problem C
 * https://codeforces.com/problemset/problem/817/C
 */

#include <iostream>
#include <numeric>

using namespace std;

long long sum_digits(long long const& n) {
  auto const str = to_string(n);
  return accumulate(str.cbegin(), str.cend(), 0LL,
                    [](long long const r, char const c) {
                      return r + (c - '0');
                    });
}

int main() {
  long long n, s;
  cin >> n >> s;
  long long l = 0, r = n + 1;
  while(l < r) {
    long long const m = l + (r - l) / 2;
    if(m - sum_digits(m) >= s) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << max(0LL, n - r + 1) << '\n';
  return 0;
}
