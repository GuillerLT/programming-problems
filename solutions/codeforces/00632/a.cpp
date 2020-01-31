/* Problemset 632 - Problem A
 * https://codeforces.com/problemset/problem/632/A
 */

#include <iostream>
#include <stack>

using namespace std;

int main() {
  long long n, p;
  cin >> n >> p;
  stack<bool> op;
  for (int i = 0; i < n - 1; ++i) {
    string s;
    cin >> s;
    op.push(s.size() == 8);
  }
  long long sol = p / 2;
  long long a = 1;
  while (!op.empty()) {
    sol += a * p;
    a *= 2;
    if (op.top()) {
      sol += p / 2;
      a += 1;
    }
    op.pop();
  }
  cout << sol << '\n';
  return 0;
}
