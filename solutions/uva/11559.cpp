/* Problem 11559
 * https://onlinejudge.org/external/115/11559.pdf
 */

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int N, B, H, W;
  while (scanf("%d %d %d %d", &N, &B, &H, &W) == 4) {
    int best = B + 1;
    for (int i = 0; i < H; ++i) {
      int p;
      cin >> p;
      p *= N;
      for (int j = 0; j < W; ++j) {
        int c;
        cin >> c;
        if (c >= N && p < best) best = p;
      }
    }
    if (best > B) {
      cout << "stay home\n";
    } else {
      cout << best << "\n";
    }
  }
}