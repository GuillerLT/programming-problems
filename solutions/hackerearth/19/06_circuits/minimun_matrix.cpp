#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  bool derecha = true;
  for (int j = 1; j <= m; ++j) {
    if (derecha) {
      for (int i = 1; i <= n; ++i) {
        cout << i << " " << j << "\n";
      }
    } else {
      for (int i = n; i >= 1; --i) {
        cout << i << " " << j << "\n";
      }
    }
    derecha = !derecha;
  }
  return 0;
}