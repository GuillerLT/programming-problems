#include <iostream>
using namespace std;

int main() {
  int n, m = 0, o = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    m += b - a;
    if (m > o) o = m;
  }
  cout << o << "\n";
  return 0;
}