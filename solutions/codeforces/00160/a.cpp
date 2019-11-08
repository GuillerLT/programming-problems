#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  int pick = 0, total = 0;
  multiset<int, greater<int>> msi;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    total += v;
    msi.insert(v);
  }
  auto v = msi.cbegin();
  int count = 0;
  while (total >= pick) {
    total -= *v;
    pick += *v;
    ++v;
    ++count;
  }
  cout << count << "\n";
  return 0;
}