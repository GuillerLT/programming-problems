#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int z = 1; z <= t; ++z) {
    cout << "Case " << z << ": ";
    int i, j, k;
    cin >> i >> j >> k;
    if ((i <= j && j <= k) || (k <= j && j <= i)) {
      cout << j;
    } else if ((i <= k && k <= j) || (j <= k && k <= i)) {
      cout << k;
    } else {
      cout << i;
    }
    cout << "\n";
  }
  return 0;
}