/* Problem 573
 * https://onlinejudge.org/external/5/573.pdf
 */

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  while (true) {
    int H;
    cin >> H;
    if (H == 0) break;
    int U, D, F;
    cin >> U >> D >> F;
    H *= 100;         // Height
    U *= 100;         // Day
    D *= 100;         // Night
    F = U * F / 100;  // Fatigue
    int p = 0;
    for (int i = 1;; ++i) {
      // Day
      p += U;
      if (p > H) {
        cout << "success on day " << i << "\n";
        break;
      }
      // Night
      p -= D;
      if (p < 0) {
        cout << "failure on day " << i << "\n";
        break;
      }
      // Fatigue
      U = max(0, U - F);
    }
  }
  return 0;
}