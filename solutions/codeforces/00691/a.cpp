/* Problemset 691 - Problem A
 * https://codeforces.com/problemset/problem/691/A
 */

#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;

int main() {
  auto it = istream_iterator<int>(cin);
  int n = *it++;
  if (accumulate(it, istream_iterator<int>(), 0) == max(1, n - 1)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
