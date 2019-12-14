/* Problem 11799
 * https://onlinejudge.org/external/117/11799.pdf
 */

#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int n;
    cin >> n;
    int f = 1;
    while (--n >= 0) {
      int s;
      cin >> s;
      if (s > f) f = s;
    }
    cout << "Case " << i << ": " << f << "\n";
  }
  return 0;
}