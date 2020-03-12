/* Problemset 762 - Problem A
 * https://codeforces.com/problemset/problem/762/A
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> vi;
  for (long long i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      if (--k == 0) {
        cout << i << '\n';
        return 0;
      } else if (i * i != n) {
        vi.push_back(i);
      }
    }
  }
  if (k > vi.size()) {
    cout << "-1\n";
  } else {
    cout << n / vi[vi.size() - k] << '\n';
  }
  return 0;
}
