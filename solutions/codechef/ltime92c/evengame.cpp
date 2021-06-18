/* Contest LTIME92C - Problem EVENGAME
 * https://www.codechef.com/LTIME92C/problems/EVENGAME
 */

#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
T get() {
  T t;
  std::cin >> t;
  return t;
}

int main() {
  for (int16_t t{get<int16_t>()}; t > 0; --t) {
    bool odd{false};
    for (int32_t n{get<int32_t>()}; n > 0; --n) {
      odd ^= get<uint32_t>() & 1;
    }
    std::cout << (odd ? "2\n" : "1\n");
  }
  return 0;
}