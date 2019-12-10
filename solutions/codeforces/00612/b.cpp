#include <iostream>
#include <array>

using namespace std;

int main() {
  int n;
  cin >> n;
  array<int, 200001> ai;
  for(int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    ai[v] = i;
  }
  long long int sol = 0;
  for(int i = 1; i < n; ++i) {
    sol += abs(ai[i] - ai[i+1]);
  }
  cout << sol << '\n';
  return 0;
}
