/* Contest LTIME69A - Problem TRICKYDL
 * https://www.codechef.com/LTIME69A/problems/TRICKYDL
 */

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    long int a, i = 2, b = 1, bb = 1;
    int bi = 2;
    cin >> a;
    while (b > 0) {
      b = (a * i) - (1L << i) + 1L;
      if (b > bb) {
        bb = b;
        bi = i;
      }
      ++i;
    }
    cout << (i - 2) << " " << bi << "\n";
  }
  return 0;
}