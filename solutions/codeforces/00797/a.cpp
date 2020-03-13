/* Problemset 797 - Problem A
 * https://codeforces.com/problemset/problem/797/A
 */

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> vi;
  for (int i = 2; i * i <= n;) {
    if (vi.size() == k - 1) {
      vi.push_back(n);
      break;
    } else if (n % i == 0) {
      n /= i;
      vi.push_back(i);
    } else {
      ++i;
    }
  }
  if (vi.size() < k && n != 1) vi.push_back(n);
  if (vi.size() == k) {
    copy(vi.cbegin(), vi.cend(), ostream_iterator<int>(cout, " "));
  } else {
    cout << "-1";
  }
  cout << '\n';
  return 0;
}
