#include <array>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    array<bool, 10> ab;
    ab.fill(false);
    int n;
    cin >> n;
    while (--n >= 0) {
      string tmp;
      cin >> tmp;
      for (size_t i = 0; i < 10; ++i) {
        ab[i] ^= (tmp[i] == '1');
      }
    }
    for (bool const& b : ab) {
      n += int(b);
    }
    cout << (n + 1) << '\n';
  }
  return 0;
}
