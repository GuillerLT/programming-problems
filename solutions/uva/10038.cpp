/* Problem 10038
 * https://onlinejudge.org/external/100/10038.pdf
 */

#include <cstdio>

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    bool jolly = true;
    vector<char> vc(n, 0);
    int prev;
    cin >> prev;
    for (int i = 1; i < n; ++i) {
      int next;
      cin >> next;
      int const diff = abs(next - prev);
      if (diff >= n || vc[diff] != 0) {
        jolly = false;
      } else {
        vc[diff] = 1;
      }
      prev = next;
    }
    cout << (jolly ? "Jolly\n" : "Not jolly\n");
  }
  return 0;
}