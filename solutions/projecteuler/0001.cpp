/* Problem 1
 * https://projecteuler.net/problem=1
 */

#include <iostream>

using namespace std;

int main() {
  long long ans = 0;
  for (int i = 1; i < 1000; ++i) {
    ans += i * ((i % 3 == 0) | (i % 5 == 0));
  }
  cout << ans << '\n';
  return 0;
}
