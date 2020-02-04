/* Problemset 660 - Problem A
 * https://codeforces.com/problemset/problem/660/A
 */

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int const c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int main() {
  int n;
  cin >> n;
  vector<int> vi(1);
  cin >> vi.front();
  for (int i = 1; i < n; ++i) {
    int v;
    cin >> v;
    if (gcd(vi.back(), v) != 1) vi.push_back(1);
    vi.push_back(v);
  }
  cout << vi.size() - n << '\n';
  for (auto const i : vi) cout << i << ' ';
  cout << '\n';
  return 0;
}
