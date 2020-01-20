/* Problemset 702 - Problem C
 * https://codeforces.com/problemset/problem/702/C
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int c, t;
  cin >> c >> t;
  vector<int> cities(c);
  for (auto& city : cities) {
    cin >> city;
  }
  set<int> towers;
  for (int i = 0; i < t; ++i) {
    int tower;
    cin >> tower;
    towers.insert(tower);
  }
  int distance = 0;
  for (auto const& city : cities) {
    auto const tower1 = towers.lower_bound(city);
    if (tower1 == towers.cbegin()) {
      distance = max(distance, *tower1 - city);
    } else if (tower1 == towers.cend()) {
      auto const tower2 = prev(tower1);
      distance = max(distance, city - *tower2);
    } else {
      auto const tower2 = prev(tower1);
      distance = max(distance, min(*tower1 - city, city - *tower2));
    }
  }
  cout << distance << '\n';
  return 0;
}
