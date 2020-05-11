/* Problemset 665 - Problem A
 * https://codeforces.com/problemset/problem/665/A
 */

#include <iostream>
#include <iterator>

using namespace std;

int main() {
  auto it = istream_iterator<int>(cin);
  int const fa = *it++;
  int const ta = *it++;
  int const fb = *it++;
  int const tb = *it;
  string s;
  cin >> s;
  int const m = (stoi(s.substr(0, 2)) - 5) * 60 + stoi(s.substr(3, 2));
  int sol = 0;
  int t = m - tb + 1;
  while (t % fb != 0) ++t;
  while (t < 0) t += fb;
  while (t < min(m + ta, 1140)) t += fb, ++sol;
  cout << sol << '\n';
}
