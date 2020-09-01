/* Problemset 962 - Problem A
 * https://codeforces.com/problemset/problem/962/A
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  vector<long long int> a(get<size_t>());
  a.front() = get<long long int>();
  for (size_t i = 1; i < a.size(); ++i) {
    a[i] = a[i - 1] + get<long long int>();
  }
  cout << lower_bound(a.cbegin(), a.cend(), *a.crbegin() / 2 + *a.crbegin() % 2,
                      std::less<long long int>{}) -
              a.cbegin() + 1
       << '\n';
  return 0;
}
