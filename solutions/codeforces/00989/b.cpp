/* Problemset 989 - Problem B
 * https://codeforces.com/problemset/problem/989/B
 */

#include <iostream>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  int const n{get<int>()}, p{get<int>()};
  string s{get<string>()};
  bool period = true;
  for (int i = p; i < n; ++i) {
    int j = i - p;
    switch (s[j]) {
      case '0':
        switch (s[i]) {
          case '0':
            continue;
          case '1':
            period = false;
            continue;
          case '.':
            period = false;
            s[i] = '1';
            continue;
        }
      case '1':
        switch (s[i]) {
          case '0':
            period = false;
            continue;
          case '1':
            continue;
          case '.':
            period = false;
            s[i] = '0';
            continue;
        }
      case '.':
        period = false;
        if (s[i] != '.') {
          bool zero = (s[i] == '1');
          for (int k = j; k >= 0; zero ^= 1, k -= p) {
            s[k] = (zero ? '0' : '1');
          }
        }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      bool zero = true;
      for (int k = i; k < n; zero ^= 1, k += p) {
        s[k] = (zero ? '0' : '1');
      }
    }
  }
  cout << (period ? string{"No"} : s) << '\n';
  return 0;
}
