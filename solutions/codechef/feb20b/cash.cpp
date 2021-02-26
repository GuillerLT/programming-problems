/* Contest FEB20B - Problem CASH
 * https://www.codechef.com/FEB20B/problems/CASH
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    copy_n(istream_iterator<int>(cin), n, back_inserter(a));
    cout << accumulate(a.cbegin(), a.cend(), 0, [k](int const b, int const c) -> int {
      return (b + c % k) % k;
    }) << '\n';
  }
  return 0;
}
