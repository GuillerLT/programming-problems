#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end(), greater<int>());
  if (v[k - 1] > 0) {
    for (int i = k - 1; k < n; ++i) {
      if (v[k - 1] != v[i]) {
        cout << i << "\n";
        return 0;
      }
    }
    cout << n << "\n";
  } else {
    while (--k > 0) {
      if (v[k - 1] > 0) {
        cout << k << "\n";
        return 0;
      }
    }
    cout << 0 << "\n";
  }
  return 0;
}