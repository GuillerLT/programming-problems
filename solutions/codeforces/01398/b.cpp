/* Problemset 1398 - Problem B
 * https://codeforces.com/problemset/problem/1398/B
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t = get<int>(); t--;) {
    string const s = get<string>();
    vector<int> blocks;
    char last_c = ' ';
    for (char const c : s) {
      if (c == '1') {
        if (c == last_c) {
          blocks.back() += 1;
        } else {
          blocks.push_back(1);
        }
      }
      last_c = c;
    }
    sort(blocks.begin(), blocks.end(), std::greater<int>{});
    int ans = 0;
    for (size_t i = 0; i < blocks.size(); i += 2) {
      ans += blocks[i];
    }
    cout << ans << '\n';
  }
  return 0;
}
