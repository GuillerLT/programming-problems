/* Problemset 632 - Problem B
 * https://codeforces.com/problemset/problem/632/B
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> pieces;
  for (int i = 0; i < n; ++i) {
    pieces.emplace_back([]() {
      int v;
      cin >> v;
      return v;
    }());
  }
  string s;
  cin >> s;
  long long val = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'B') {
      val += pieces[i];
    }
  }
  long long best_val = val;
  for (int r = 0; r < n; ++r) {
    if (s[r] == 'B') {
      val -= pieces[r];
    } else {
      val += pieces[r];
    }
    best_val = max(best_val, val);
  }
  for (int l = 0; l < n; ++l) {
    if (s[l] == 'B') {
      val += pieces[l];
    } else {
      val -= pieces[l];
    }
    best_val = max(best_val, val);
  }
  cout << best_val << '\n';
  return 0;
}
