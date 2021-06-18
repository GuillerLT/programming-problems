/* Contest JUNE21C - Problem BITTUP
 * https://www.codechef.com/JUNE21C/problems/BITTUP
 */

#include <iostream>
#include <iterator>

constexpr unsigned long long mod{1'000'000'000 + 7};

constexpr unsigned long long mul(unsigned long long const a,
                                 unsigned long long const b) {
  return (a * b) % mod;
}

constexpr unsigned long long pow(unsigned long long const base,
                                 unsigned long long const exp) {
  auto const aux{exp ? pow(base, exp >> 1) : 1};
  return mul(mul(aux, aux), exp & 1 ? base : 1);
}

constexpr unsigned long long sub(unsigned long long const a,
                                 unsigned long long const b) {
  return (a + mod - b) % mod;
}

int main() {
  std::istream_iterator<int> in_it{std::cin};
  for (int t{*(in_it++)}; t > 0; --t) {
    int const n{*(in_it++)};
    int const m{*(in_it++)};
    std::cout << pow(sub(pow(2, n), 1), m) << '\n';
  }
  return 0;
}
