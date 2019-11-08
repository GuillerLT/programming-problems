#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int& j : v) {
    for (int i = 0; i < 3; ++i) {
      int k;
      cin >> k;
      j += k;
    }
  }
  int s = 0;
  for (int& j : v) {
    if (j >= 2) {
      ++s;
    }
  }
  cout << s << "\n";
  return 0;
}