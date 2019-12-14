/* Contest FEB19B - Problem MAGICJAR
 * https://www.codechef.com/FEB19B/problems/MAGICJAR
 */

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    unsigned long long sol = 1;
    int n;
    cin >> n;
    while (--n >= 0) {
      unsigned long long s;
      cin >> s;
      sol += (s - 1);
    }
    cout << sol << '\n';
  }
  return 0;
}