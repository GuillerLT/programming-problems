#include <iostream>

using namespace std;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  int min = n + 1;
  for (int i = 0; i < n; ++i) {
    bool correct = true;
    for (int j = 0; i + j < n; ++j) {
      if (s[i + j] != t[j]) {
        correct = false;
        break;
      }
    }
    if (correct && i < min) {
      min = i;
    }
  }
  cout << min << "\n";
  return 0;
}