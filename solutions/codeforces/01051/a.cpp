/* Problemset 1051 - Problem A
 * https://codeforces.com/problemset/problem/1051/A
 */


#include <iostream>

template <class T>
T get() {
  T t;
  std::cin >> t;
  return t;
}

int main() {
  for (int t{get<int>()}; t > 0; --t) {
    std::string s{get<std::string>()};
    int lower{0}, upper{0}, number{0};
    for (char const c : s) {
      lower += (c >= 'a' && c <= 'z');
      upper += (c >= 'A' && c <= 'Z');
      number += (c >= '0' && c <= '9');
    }
    if (lower == s.size()) {
      s[0] = 'A';
      s[1] = '0';
    } else if (upper == s.size()) {
      s[0] = 'a';
      s[1] = '0';
    } else if (number == s.size()) {
      s[0] = 'a';
      s[1] = 'A';
    } else {
      for (char& c : s) {
        if (c >= 'a' && c <= 'z' && lower > 1) {
          if (upper == 0) {
            c = 'A';
          } else if (number == 0) {
            c = '0';
          }
          break;
        } else if (c >= 'A' && c <= 'Z' && upper > 1) {
          if (lower == 0) {
            c = 'a';
          } else if (number == 0) {
            c = '0';
          }
          break;
        } else if (c >= '0' && c <= '9' && number > 1) {
          if (lower == 0) {
            c = 'a';
          } else if (upper == 0) {
            c = 'A';
          }
          break;
        }
      }
    }
    std::cout << s << '\n';
  }
  return 0;
}
