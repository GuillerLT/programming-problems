#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ++n;
    int cnt = 0;
    while(n >>= 1) {
      ++cnt;
    }
    cout << ((~0U) >> (sizeof(int) * 8 - cnt)) << '\n';
  }
  return 0;
}
