/* Contest JUNE17 - Problem GOODSET
 * https://www.codechef.com/JUNE17/problems/GOODSET
 */

#include <algorithm>
#include <iostream>
#include <iterator>

template <class T>
T get() {
  T t;
  std::cin >> t;
  return t;
}

int main() {
  for (int n{get<int>()}; n > 0; --n) {
    std::generate_n(std::ostream_iterator<int>{std::cout, " "},
                    get<int>(),
                    [n = 1u]() mutable { return n += 2; });
    std::cout.put('\n');
  }
  return 0;
}