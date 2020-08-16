/* Problemset 1398 - Problem C
 * https://codeforces.com/problemset/problem/1398/C
 */

#include <iostream>
#include <iterator>
#include <map>
#include <numeric>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t = get<int>(); t--;) {
    map<long long, long long> freq{{0, 1}};
    long long ans = 0, cnt = 0;
    size_t const n = get<int>();
    string const s = get<string>();
    for (int i = 0; i < n; ++i) {
      cnt += static_cast<long long>(s[i] - '0');
      long long &f = freq[cnt - i - 1];
      ans += f;
      ++f;
    }
    cout << ans << '\n';
  }
  return 0;
}
