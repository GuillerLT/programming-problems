/* Problemset 4 - Problem A
 * https://codeforces.com/problemset/problem/4/A
 */

#include <iostream>
using namespace std;
int main() {
  int i;
  cin >> i;
  if (i == 2 || i % 2 == 1)
    cout << "NO"
         << "\n";
  else
    cout << "YES"
         << "\n";
  return 0;
}