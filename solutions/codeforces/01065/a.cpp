/* Problemset 1065 - Problem A
 * https://codeforces.com/problemset/problem/1065/A
 */

#include <iostream>

template<class T>
T get() {
  T t;
  std::cin >> t;
  return t;
}

int main() {
  for (int t{get<int>()}; t > 0; --t) {
    long long const money{get<int>()}, min{get<int>()}, free{get<int>()}, cost{get<int>()};
    std::cout << (money / cost) + free * ((money / cost) / min) << '\n';
  }
  return 0;
}
