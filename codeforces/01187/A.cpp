#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    int n, s, t;
    cin >> n >> s >> t;
    cout << max(n - t, n - s) + 1 << "\n";
  }
  return 0;
}