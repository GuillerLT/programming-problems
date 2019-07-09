#include <iostream>
#include <vector>
using namespace std;

int main() {
  int i;
  cin >> i;
  while (--i >= 0) {
    int sol = -1;
    int j;
    cin >> j;
    vector<int> va, vd;
    va.reserve(j);
    vd.reserve(j);
    for (int k = 0; k < j; ++k) {
      int a;
      cin >> a;
      va.push_back(a);
    }
    for (int k = 0; k < j; ++k) {
      int d;
      cin >> d;
      vd.push_back(d);
    }
    for (int k = 0; k < j; ++k) {
      int const val = vd[k] - va[(k + 1) % j] - va[(k + j - 1) % j];
      if (val > 0 && vd[k] > sol) sol = vd[k];
    }
    cout << sol << '\n';
  }
  return 0;
}