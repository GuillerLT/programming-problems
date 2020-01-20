/* Problemset 691 - Problem C
 * https://codeforces.com/problemset/problem/691/C
 */

#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  s += '.';
  string t;
  size_t l, r;
  l = s.find_first_not_of('0');
  r = s.find_first_of('.', l);
  t += s.substr(l, r - l);
  int e = r - l - 1;
  l = r + 1;
  r = s.find_last_not_of('0', s.size() - 2);
  t += s.substr(l, r - l + 1);
  if (t.empty()) {
    cout << "0\n";
  } else {
    l = t.find_first_not_of('0');
    r = t.find_last_not_of('0');
    t = t.substr(l, r - l + 1);
    e -= l;
    cout << t.front();
    if (t.size() > 1) cout << '.' << t.substr(1);
    if (e != 0) cout << 'E' << e;
    cout << '\n';
  }
  return 0;
}
