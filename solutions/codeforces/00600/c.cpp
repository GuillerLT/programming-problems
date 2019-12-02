#include <array>
#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  array<int, 'z' - 'a' + 1> f;
  f.fill(0);
  for (char const c : s) ++f[c - 'a'];
  int first = 0, last = 'z' - 'a';
  while (true) {
    while (f[first] % 2 == 0) ++first;
    while (f[last] % 2 == 0) --last;
    if (first >= last) break;
    ++f[first];
    --f[last];
  }
  for (int i = 0; i < f.size(); ++i) {
    for (int j = 0; j < f[i] / 2; ++j) {
      cout << static_cast<char>('a' + i);
    }
  }
  if (s.size() % 2 == 1) cout << static_cast<char>('a' + first);
  for (int i = f.size() - 1; i >= 0; --i) {
    for (int j = 0; j < f[i] / 2; ++j) {
      cout << static_cast<char>('a' + i);
    }
  }
  cout << '\n';
  return 0;
}
