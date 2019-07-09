#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    vector<size_t> cont(33, 0);
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
      string s;
      cin >> s;
      size_t v = 0;
      size_t const j_end = s.size();
      for (size_t j = 0; j < j_end; ++j) {
        char const& c = s[j];
        switch (c) {
          case 'a':
            v |= 16;
            break;
          case 'e':
            v |= 8;
            break;
          case 'i':
            v |= 4;
            break;
          case 'o':
            v |= 2;
            break;
          case 'u':
            v |= 1;
            break;
        }
      }
      ++cont[v];
    }
    size_t res = 0;
    for (size_t i = 0; i <= 31; ++i) {
      for (size_t j = i + 1; j <= 31; ++j) {
        if ((i | j) == 31) {
          res += cont[i] * cont[j];
          if (i == j) res -= cont[i];
        }
      }
    }
    res += (cont[31] * cont[31] - cont[31]) / 2;
    cout << res << "\n";
  }
  return 0;
}