/* Problemset 903 - Problem B
 * https://codeforces.com/problemset/problem/903/B
 */

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  int h1 = get<int>(),  //
      a1 = get<int>(),  //
      c1 = get<int>(),  //
      h2 = get<int>(),  //
      a2 = get<int>();
  vector<int> turns;
  while (h2 > 0) {
    if (h2 <= a1 || h1 > a2) {
      turns.push_back(1);
      h2 -= a1;
    } else {
      turns.push_back(0);
      h1 += c1;
    }
    h1 -= a2;
  }
  cout << turns.size() << '\n';
  for (auto const turn : turns) {
    cout << (turn == 1 ? "STRIKE\n" : "HEAL\n");
  }
  return 0;
}
