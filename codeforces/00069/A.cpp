#include <iostream>
using namespace std;

int main() {
  int x = 0, y = 0, z = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    x += a;
    y += b;
    z += c;
  }
  if (x == 0 && y == 0 && z == 0)
    cout << "YES";
  else
    cout << "NO";
  cout << "\n";
  return 0;
}