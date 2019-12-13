/* Problemset 1189 - Problem B
 * https://codeforces.com/problemset/problem/1189/B
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vi(n);
  for (int& i : vi) cin >> i;
  sort(vi.begin(), vi.end());
  if (vi[n - 2] + vi[n - 3] - vi[n - 1] > 0) {
    cout << "YES\n";
    list<int> l;
    l.push_front(vi.back());
    vi.pop_back();
    while (!vi.empty()) {
      if (l.front() > l.back()) {
        l.push_front(vi.back());
      } else {
        l.push_back(vi.back());
      }
      vi.pop_back();
    }
    for (auto const& i : l) {
      cout << i << " ";
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}