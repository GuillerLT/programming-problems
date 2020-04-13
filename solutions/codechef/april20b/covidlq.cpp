/* Contest APRIL20B - Problem COVIDLQ
 * https://www.codechef.com/APRIL20B/problems/COVIDLQ
 */

#include <iostream>
#include <iterator>

using namespace std;

int main() {
  for (int t = *istream_iterator<int>(cin); t--;) {
    int cnt = 6, ok = true;
    for (int n = *istream_iterator<int>(cin); n--;) {
      bool const ai = *istream_iterator<bool>(cin);
      ok &= (!ai) | (cnt >= 6);
      cnt = int{!ai} * cnt + 1;
    }
    cout << (ok ? "YES\n"s : "NO\n"s);
  }
  return 0;
}
