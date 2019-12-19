#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for (auto& c : s) {
    int dl = c - 'a';
    int dr = 'z' - c;
    if (dl > dr) {
      dl = min(dl, m);
      c -= dl;
      m -= dl;
    } else {
      dr = min(dr, m);
      c += dr;
      m -= dr;
    }
  }
  if (m > 0) {
    cout << "-1\n";
  } else {
    cout << s << '\n';
  }
  return 0;
}
