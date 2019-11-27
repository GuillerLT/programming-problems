#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int t;
  cin >> t;
  while (--t >= 0) {
    int l, r, k;
    cin >> l >> r >> k;
    k %= (r - l + 1);
    if (k > 0) {
      rotate(s.begin() + l - 1, s.begin() + r - k, s.begin() + r);
    }
  }
  cout << s << '\n';
  return 0;
}
