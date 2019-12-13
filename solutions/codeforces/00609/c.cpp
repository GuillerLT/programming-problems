/* Problemset 609 - Problem C
 * https://codeforces.com/problemset/problem/609/C
 */

#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  array<int, 100000> ai;
  int avg = 0, exc;
  for (int i = 0; i < n; ++i) {
    cin >> ai[i];
    avg += ai[i];
  }
  sort(ai.begin(), ai.begin() + n);
  exc = avg % n;
  avg /= n;
  int total = 0;
  for (int i = 0; i < n - exc; ++i) {
    total += abs(avg - ai[i]);
  }
  for (int i = n - exc; i < n; ++i) {
    total += abs(avg + 1 - ai[i]);
  }
  cout << total / 2 << '\n';
}
