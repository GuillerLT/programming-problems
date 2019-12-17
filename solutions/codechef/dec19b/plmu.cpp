#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    int n;
    cin >> n;
    long long d = 0, z = 0;
    while (--n >= 0) {
      int v;
      cin >> v;
      d += int(v == 2);
      z += int(v == 0);
    }
    cout << d * (d - 1) / 2 + z * (z - 1) / 2 << '\n';
  }
  return 0;
}