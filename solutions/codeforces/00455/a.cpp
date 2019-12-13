/* Problemset 455 - Problem A
 * https://codeforces.com/problemset/problem/455/A
 */

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

constexpr long long limit = 100000;

int main() {
  long long n;
  cin >> n;
  vector<long long> vt(limit + 3, 0);
  for (long long i = 0; i < n; ++i) {
    long long v;
    cin >> v;
    ++vt[v];
  }
  for (long long i = limit; i >= 0; --i) {
    vt[i] = max(vt[i] * i + vt[i + 2], vt[i + 1]);
  }
  cout << vt.front() << "\n";
  return 0;
}