/* Problemset 665 - Problem C
 * https://codeforces.com/problemset/problem/665/C
 */

#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  size_t n = s.size();
  s.push_back('\n');
  for(size_t i = 0; i < n; ++i) {
    if (s[i] == s[i+1]) {
      for(char j = 'a'; j <= 'z'; ++j) {
        if(j != s[i] && j != s[i+2]) {
          s[++i] = j;
          break;
        }
      }
    }
  }
  cout << s;
  return 0;
}
