#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int, greater<int>> si;
  while (--n >= 0) {
    int x;
    cin >> x;
    si.emplace(x);
  }
  int max = 0;
  for (int const& i : si) {
    if (i > max) {
      for (int const& j : si) {
        if (j > max) {
          int const val = i % j;
          if (val > max) max = val;
        } else {
          break;
        }
      }
    } else {
      break;
    }
  }
  cout << max << "\n";
  return 0;
}