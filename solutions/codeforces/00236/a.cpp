/* Problemset 236 - Problem A
 * https://codeforces.com/problemset/problem/236/A
 */

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  string s;
  cin >> s;
  unordered_set<char> usc;
  for (char const& c : s) usc.insert(c);
  if (usc.size() % 2)
    cout << "IGNORE HIM!"
         << "\n";
  else
    cout << "CHAT WITH HER!"
         << "\n";
  return 0;
}