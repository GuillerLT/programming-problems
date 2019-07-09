#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    int i, j;
    cin >> i >> j;
    if (i < j) {
      cout << "<\n";
    } else if (i > j) {
      cout << ">\n";
    } else {
      cout << "=\n";
    }
  }
  return 0;
}