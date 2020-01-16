/* Problemset 660 - Problem C
 * https://codeforces.com/problemset/problem/660/C
 */

#include <array>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<bool> values;
  for (int i = 0; i < n; ++i) {
    bool b;
    cin >> b;
    values.push_back(b);
  }
  // for (int i = 0; i < n; ++i) cout << values[i] << ' ';
  // cout << '\n';
  array<int, 2> cnt{0, 0};
  int l = 0, r = 0, bl = 0, br = 0, b = 0;
  while (true) {
    if (l == n) break;
    while (true) {
      if (cnt[0] > k) {
        --cnt[0];
        --r;
        break;
      } else {
        if (r == n) break;
        ++cnt[values[r]];
        ++r;
      }
    }
    if (cnt[0] + cnt[1] > b) {
      b = cnt[0] + cnt[1];
      bl = l;
      br = r;
    }
    --cnt[values[l]];
    ++l;
  }
  cout << br - bl << '\n';
  for (int i = 0; i < bl; ++i) cout << values[i] << ' ';
  for (int i = bl; i < br; ++i) cout << "1 ";
  for (int i = br; i < n; ++i) cout << values[i] << ' ';
  cout << '\n';
  return 0;
}
