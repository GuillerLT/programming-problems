/* Problemset 702 - Problem B
 * https://codeforces.com/problemset/problem/702/B
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<int, int> cnt;
  for_each(next(istream_iterator<int>(cin)), istream_iterator<int>(),
           [&cnt](int const i) { ++cnt[i]; });
  long long ans = 0;
  for (auto const& it : cnt) {
    for (int i = 1; i > 0; i <<= 1) {
      int const query = i - it.first;
      if (query == it.first) {
        ans += static_cast<long long>(it.second) *
               (static_cast<long long>(it.second) - 1LL) / 2LL;
      } else if (query > it.first) {
        auto it2 = cnt.find(query);
        if (it2 != cnt.cend())
          ans += static_cast<long long>(it.second) *
                 static_cast<long long>(it2->second);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
