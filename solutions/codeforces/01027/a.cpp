/* Problemset 1027 - Problem A
 * https://codeforces.com/problemset/problem/1027/A
 */

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t = get<int>(); t > 0; --t) {
    int const n = get<int>();
    string const s = get<string>();
    bool ans = true;
    for (int i = n / 2; i > 0; --i) {
      int const distance = abs(int{s[i - 1] - s[n - i]});
      ans &= distance == 0 || distance == 2;
    }
    cout << (ans ? "YES\n" : "NO\n");
  }
  return 0;
}
