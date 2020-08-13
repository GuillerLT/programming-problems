/* Problemset 938 - Problem A
 * https://codeforces.com/problemset/problem/938/A
 */

#include <iostream>

using namespace std;

int main() {
  string s, t;
  cin >> s >> s;
  bool last_vowel = false;
  for (char const c : s) {
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'y':
        if (!last_vowel) t += c;
        last_vowel = true;
        break;
      default:
        t += c;
        last_vowel = false;
    }
  }
  cout << t << '\n';
  return 0;
}
