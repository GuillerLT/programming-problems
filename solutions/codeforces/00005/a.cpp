/* Problemset 5 - Problem A
 * https://codeforces.com/problemset/problem/5/A
 */

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int first_even = n, first_odd = n, bal = 0;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    if (v % 2 == 0) {
      if (first_even > i) first_even = i;
      ++bal;
    } else {
      if (first_odd > i) first_odd = i;
      --bal;
    }
  }
  if (bal > 0) {
    cout << ++first_odd << "\n";
  } else {
    cout << ++first_even << "\n";
  }
  return 0;
}