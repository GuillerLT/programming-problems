#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int k, n, w;
  cin >> k >> n >> w;
  cout << max(0, k * (w * w + w) / 2 - n) << "\n";
  return 0;
}