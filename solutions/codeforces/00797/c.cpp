/* Problemset 797 - Problem C
 * https://codeforces.com/problemset/problem/797/C
 */

#include <array>
#include <iostream>

using namespace std;

int main() {
  string s, t, u;
  cin >> s;
  array<int, 'z' - 'a' + 1> hist;
  hist.fill(0);
  for(char const c : s) {
    ++hist[c - 'a'];
  }
  size_t j = 0;
  for(char i = 'a'; i <= 'z'; ++i) {
    while(!t.empty() && t.back() <= i) {
      u += t.back();
      t.pop_back();
    }
    while(hist[i - 'a'] > 0) {
      if(s[j] == i) {
        u += s[j];
        --hist[i - 'a'];
      } else {
        t += s[j];
        --hist[s[j] - 'a'];
      }
      ++j;
    }
  }
  cout << u << string(t.crbegin(), t.crend()) << '\n';
  return 0;
}
