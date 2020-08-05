/* Problemset 903 - Problem C
 * https://codeforces.com/problemset/problem/903/C
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  vector<int> boxes(get<size_t>());
  copy_n(istream_iterator<int>(cin), boxes.size(), boxes.begin());
  sort(boxes.begin(), boxes.end(), greater<int>{});
  multiset<int> groups;
  for (int const box : boxes) {
    auto it = groups.upper_bound(box);
    if (it != groups.cend()) {
      groups.erase(it);
    }
    groups.insert(box);
  }
  cout << groups.size() << endl;
  return 0;
}
