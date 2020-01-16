/* Problemset 620 - Problem C
 * https://codeforces.com/problemset/problem/620/C
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> segments;
  set<int> pearls;
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    if(!pearls.insert(p).second) {
      pearls.clear();
      segments.push_back(i);
    }
  }
  if (segments.size() > 0) {
    if (segments.back() != n) segments.back() = n;
    cout << segments.size() << "\n1 ";
    for (auto const s : segments) {
      cout << s << '\n';
      if (s < n) cout << s + 1 << ' ';
    }
  } else {
    cout << "-1\n";
  }
  return 0;
}
