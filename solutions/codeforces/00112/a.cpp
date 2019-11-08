#include <iostream>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int sol = 0;
  for (size_t i = 0; i < s.length(); ++i) {
    char &c = s[i], &d = t[i];
    if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
    if (d >= 'A' && d <= 'Z') d += 'a' - 'A';
    if (c > d) {
      sol = 1;
      break;
    } else if (c < d) {
      sol = -1;
      break;
    }
  }
  cout << sol << "\n";
}