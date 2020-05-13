/* Problem 44
 * https://projecteuler.net/problem=44
 */

#include <cmath>
#include <iostream>
using namespace std;

auto P(long long const n) { return n * (3LL * n - 1LL) / 2LL; };

auto is_P(long long const n) { return fmod((1 + sqrt(1 + 24 * n)), 6) == 0; }

int main() {
  for (long long k = 2;; k += 1) {
    long long const Pk = P(k);
    for (long long j = k - 1; j >= 1; j -= 1) {
      long long const Pj = P(j);
      long long const sum = Pk + Pj, diff = Pk - Pj;
      if (is_P(sum) && is_P(diff)) {
        cout << diff << '\n';
        return 0;
      }
    }
  }
}
