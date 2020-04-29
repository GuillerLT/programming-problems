/* Problemset 466 - Problem C
 * https://codeforces.com/problemset/problem/466/C
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  size_t const n = *istream_iterator<size_t>(cin);
  vector<long long> a(n);
  copy_n(istream_iterator<long long>(cin), n, a.begin());
  partial_sum(a.cbegin(), a.cend(), a.begin());
  if (a.size() >= 3 && a.back() % 3 == 0) {
    long long const b = a.back() / 3;
    long long const c = b * 2;
    cout << accumulate(a.cbegin(), prev(a.cend()), make_pair(0LL, 0LL),
                       [b, c](pair<long long, long long> ans, long long const a) {
                         if (a == c) {
                           ans.second += ans.first;
                         }
                         if (a == b) {
                           ++ans.first;
                         }
                         return ans;
                       })
                .second
         << '\n';
  } else {
    cout << "0\n";
  }
  return 0;
}
