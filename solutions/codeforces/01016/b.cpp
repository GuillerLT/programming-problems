/* Problemset 1016 - Problem B
 * https://codeforces.com/problemset/problem/1016/B
 */

#include <algorithm>
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
  int const n = get<int>(),
            m = get<int>(),
            q = get<int>();
  string const s = get<string>(),
               t = get<string>();
  vector<int> ans{0};
  for (size_t i = 0; i + m <= n; ++i) {
    ans.push_back(ans.back() + equal(t.cbegin(), t.cend(), s.cbegin() + i));
  }
  ans.insert(ans.end(), n - ans.size() + 1, ans.back());
  for (int i = 0; i < q; ++i) {
    int const l = get<int>(),
              r = get<int>();
    cout << ((r - m + 1 > l - 1) ? ans[r - m + 1] - ans[l - 1] : 0) << '\n';
  }
}
