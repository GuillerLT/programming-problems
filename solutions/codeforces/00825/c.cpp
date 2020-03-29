/* Problemset 825 - Problem C
 * https://codeforces.com/problemset/problem/825/C
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  copy_n(istream_iterator<int>(cin), n, a.begin());
  sort(a.begin(), a.end());
  int sol = 0;
  for_each(a.cbegin(), a.cend(), [&k, &sol](int const& ai) {
    while (ai > k * 2) {
      k *= 2;
      ++sol;
    }
    k = max(k, ai);
  });
  cout << sol << endl;
}
