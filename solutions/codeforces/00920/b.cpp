/* Problemset 920 - Problem B
 * https://codeforces.com/problemset/problem/920/B
 */

#include <iostream>
#include <utility>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t = get<int>(); t--;) {
    int current_time = 1;
    for (int i = get<int>(); i--;) {
      auto const l = get<int>();
      auto const r = get<int>();
      if (current_time > r) {
        cout << "0 ";
      } else {
        current_time = max(current_time, l);
        cout << current_time << ' ';
        ++current_time;
      }
    }
    cout << '\n';
  }
  return 0;
}
