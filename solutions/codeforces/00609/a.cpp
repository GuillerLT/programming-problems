#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  array<int, 100> ai;
  for(int i = 0; i < n; ++i) cin >> ai[i];
  sort(ai.begin(), ai.begin() + n, std::greater<int>());
  int i = 0;
  while(m > 0) {
    m -= ai[i++];
  }
  cout << i << '\n';
}
