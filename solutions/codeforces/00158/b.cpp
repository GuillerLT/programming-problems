#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<char, int> umci;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    ++umci[c];
  }
  // 4
  int sol = umci['4'];
  // 3
  sol += umci['3'];
  // 3 + 1
  umci['1'] -= umci['3'];
  // 2
  sol += umci['2'] / 2;
  // 2 + 1 + 1
  if (umci['2'] % 2) {
    ++sol;
    umci['1'] -= 2;
  }
  // 1 + 1 + 1 + 1
  if (umci['1'] > 0) {
    sol += umci['1'] / 4;
    if (umci['1'] % 4) ++sol;
  }
  cout << sol << "\n";
  return 0;
}