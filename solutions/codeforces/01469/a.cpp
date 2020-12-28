/* Problemset 1469 - Problem A
 * https://codeforces.com/problemset/problem/1469/A
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

template <class T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t{get<int>()}; t > 0; --t) {
    string const s{get<string>()};
    if (s.size() % 2 == 1) {
      cout << "no\n";
    } else {
      auto open = find(s.cbegin(), s.cend(), '('),
           close = find(s.cbegin(), s.cend(), ')');
      if (open < close) {
        cout << "yes\n";
      } else {
        int const left = close - s.cbegin(), right = s.cend() - open - 1;
        if (left == 0 || right == 0) {
          cout << "no\n";
        } else {
          cout << "yes\n";
        }
      }
    }
  }
  return 0;
}
