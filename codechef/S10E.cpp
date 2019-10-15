#include <array>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    int n;
    cin >> n;
    int cnt = 0;
    array<int, 5> ai;
    ai.fill(777);
    for (int i = 0; i < n; ++i) {
      int p;
      cin >> p;
      bool lower = true;
      for (int j = 0; j < 5; ++j) {
        lower &= (ai[j] > p);
      }
      cnt += (int)lower;
      ai[i % 5] = p;
    }
    cout << cnt << "\n";
  }
  return 0;
}
