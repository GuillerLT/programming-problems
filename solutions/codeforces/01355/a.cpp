/* Problemset 1355 - Problem A
 * https://codeforces.com/problemset/problem/1355/A
 */

#include <iostream>
#include <iterator>
#include <limits>

using namespace std;

long long min_max_digit(long long a) {
  long long min = 10;
  long long max = -1;
  for (; a > 0; a /= 10) {
    long long const d = a % 10;
    min = std::min(min, d);
    max = std::max(max, d);
  }
  return min * max;
}

int main() {
  auto it = istream_iterator<long long>(cin);
  for (long long t = *it; t > 0; --t) {
    long long an = *++it;
    long long const k = *++it;
    for (long long i = 1; i < k; ++i) {
      long long const min_max = min_max_digit(an);
      an += min_max;
      if (min_max == 0) break;
    }
    cout << an << '\n';
  }
  return 0;
}
