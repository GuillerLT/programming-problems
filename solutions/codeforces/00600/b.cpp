#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vi(n);
  for (auto &a : vi) cin >> a;
  sort(vi.begin(), vi.end());
  while (--m >= 0) {
    int b;
    cin >> b;
    auto it = upper_bound(vi.cbegin(), vi.cend(), b);
    cout << it - vi.cbegin() << '\n';
  }
  return 0;
}
