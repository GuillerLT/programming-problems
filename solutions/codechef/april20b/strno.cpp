/* Contest APRIL20B - Problem STRNO
 * https://www.codechef.com/APRIL20B/problems/STRNO
 */

#include <iostream>
#include <iterator>

using namespace std;

int main() {
  for (int t = *istream_iterator<int>{cin}; t; --t) {
    int x, k;
    cin >> x >> k;
    int cnt = 0;
    for (int i = 2; i * i <= x; ++i) {
      while (x % i == 0) {
        x /= i;
        ++cnt;
      }
    }
    cout << ((cnt + int{x > 1}) >= k) << '\n';
  }
  return 0;
}
