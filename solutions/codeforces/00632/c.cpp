/* Problemset 632 - Problem C
 * https://codeforces.com/problemset/problem/632/C
 */

#include <iostream>
#include <set>

using namespace std;

class cmp {
 public:
  bool operator()(string const& s1, string const& s2) const {
    return s1 + s2 < s2 + s1;
  }
};

int main() {
  multiset<string, cmp> ss;
  int n;
  cin >> n;
  while(--n >= 0) {
    string s;
    cin >> s;
    ss.insert(move(s));
  }
  for (string const& s : ss) {
    cout << s;
  }
  cout << '\n';
  return 0;
}
