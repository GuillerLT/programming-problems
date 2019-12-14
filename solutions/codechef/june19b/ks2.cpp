/* Contest JUNE19B - Problem KS2
 * https://www.codechef.com/JUNE19B/problems/KS2
 */

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    string s;
    cin >> s;
    int val = 0;
    for (char const& c : s) val += c - '0';
    cout << s << (char)((10 - val) % 10 + '0') << "\n";
  }
  return 0;
}