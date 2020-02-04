/* Problemset 660 - Problem B
 * https://codeforces.com/problemset/problem/660/B
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> wl, wr, al, ar;
  int id = 1;
  for (int i = 0; i < n; ++i) {
    if (m > 0) {
      wl.push_back(id++);
      --m;
    }
    if (m > 0) {
      wr.push_back(id++);
      --m;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (m > 0) {
      al.push_back(id++);
      --m;
    }
    if (m > 0) {
      ar.push_back(id++);
      --m;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (al.size() > i) {
      cout << al[i] << ' ';
    }
    if (wl.size() > i) {
      cout << wl[i] << ' ';
    }
    if (ar.size() > i) {
      cout << ar[i] << ' ';
    }
    if (wr.size() > i) {
      cout << wr[i] << ' ';
    }
  }
  cout << '\n';
  return 0;
}
