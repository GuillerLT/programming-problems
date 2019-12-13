/* Problemset 281 - Problem A
 * https://codeforces.com/problemset/problem/281/A
 */

#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  char& c = s.front();
  if (c >= 'a' && c <= 'z') c += ('A' - 'a');
  cout << s << "\n";
  return 0;
}