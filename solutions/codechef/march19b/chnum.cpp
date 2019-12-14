/* Contest MARCH19B - Problem CHNUM
 * https://www.codechef.com/MARCH19B/problems/CHNUM
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    int n, pos = 0, neg = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a >= 0)
        ++pos;
      else
        ++neg;
    }
    if (pos == 0)
      cout << neg << " " << neg << "\n";
    else if (neg == 0)
      cout << pos << " " << pos << "\n";
    else
      cout << max(pos, neg) << " " << min(pos, neg) << "\n";
  }
  return 0;
}