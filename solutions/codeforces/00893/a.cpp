/* Problemset 893 - Problem A
 * https://codeforces.com/problemset/problem/893/A
 */

#include <array>
#include <iostream>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  array<bool, 3> playing{1, 1, 0};
  for (int n = get<int>(); n > 0; --n) {
    int const winner = get<int>() - 1;
    for (int i = 0; i < 3; ++i) {
      if (i == winner) {
        if (!playing[winner]) {
          cout << "NO\n";
          return 0;
        }
      } else {
        playing[i] = !playing[i];
      }
    }
  }
  cout << "YES\n";
  return 0;
}
