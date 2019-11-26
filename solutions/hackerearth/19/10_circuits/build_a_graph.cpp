#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n >= 12) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}

/* Minimum component (6)
 * _________
 * |       |
 * A - B - C
 * |   |   |
 * D   E   F
 *
 * Vertices:
 *      A, B, C, D, E, F
 * Edges:
 *      A-B
 *      A-C
 *      A-D
 *      B-C
 *      B-E
 *      C-F
 */