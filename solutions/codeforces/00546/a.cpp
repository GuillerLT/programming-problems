/* Problemset 546 - Problem A
 * https://codeforces.com/problemset/problem/546/A
 */

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int k, n, w;
  cin >> k >> n >> w;
  cout << max(0, k * (w * w + w) / 2 - n) << "\n";
  return 0;
}