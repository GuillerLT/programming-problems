/* Problemset 1360 - Problem D
 * https://codeforces.com/problemset/problem/1360/D
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t = get<int>(); t > 0; --t) {
    long long const n = get<int>(), k = get<int>();
    vector<long long> primes;
    long long aux = n;
    for (long long i = 2; i * i <= aux; ++i) {
      while (aux % i == 0) {
        primes.push_back(i);
        aux /= i;
      }
    }
    primes.push_back(aux);
    set<long long> combs;
    for (long long const prime : primes) {
      if (prime <= k) {
        set<long long> aux;
        aux.insert(prime);
        for (long long const comb : combs) {
          long long const val = prime * comb;
          if (val <= k) aux.insert(val);
        }
        combs.insert(aux.cbegin(), aux.cend());
      }
    }
    combs.insert(1);
    cout << n / *combs.crbegin() << '\n';
  }
  return 0;
}
