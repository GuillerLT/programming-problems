#include <iostream>
#include <array>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  array<int, 10> ai;
  ai.fill(0);
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    ++ai[m-1];
  }
  int sol = 0;
  for (int i = 0; i < 10; ++i) {
    for (int j = i + 1; j < 10; ++j) {
      sol += ai[i] * ai[j];
    }
  }
  cout << sol << '\n';
  return 0;
}
