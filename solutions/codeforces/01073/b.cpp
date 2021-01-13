/* Problemset 1073 - Problem B
 * https://codeforces.com/problemset/problem/1073/B
 */

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int get() {
  int t;
  scanf("%d", &t);
  return t;
}

int main() {
  int const n{get()};
  vector<pair<int, int>> position(n);
  for (int i = 0; i < n; ++i) {
    position[i].first = get();
    position[i].second = i + 1;
  }
  sort(position.begin(), position.end());
  int max_position = 0;
  for (int i = 0; i < n; ++i) {
    int const cur_position{
        lower_bound(position.cbegin(), position.cend(), make_pair(get(), 0))
            ->second};
    cout << max(0, cur_position -
                       exchange(max_position, max(max_position, cur_position)))
         << ' ';
  }
  cout << '\n';
  return 0;
}
