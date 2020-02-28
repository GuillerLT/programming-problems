/* Contest FEB20B - Problem SNUG_FIT
 * https://www.codechef.com/FEB20B/problems/SNUG_FIT
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a, b;
    copy_n(istream_iterator<int>(cin), n, back_insert_iterator<vector<int>>(a));
    copy_n(istream_iterator<int>(cin), n, back_insert_iterator<vector<int>>(b));
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long sol = 0;
    for (int i = 0; i < n; ++i) sol += static_cast<long long>(min(a[i], b[i]));
    cout << sol << '\n';
  }
  return 0;
}
