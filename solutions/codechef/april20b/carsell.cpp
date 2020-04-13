/* Contest APRIL20B - Problem CARSELL
 * https://www.codechef.com/APRIL20B/problems/CARSELL
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  for (int t = *istream_iterator<int>{cin}; t; --t) {
    vector<int> p(*istream_iterator<size_t>{cin});
    copy_n(istream_iterator<int>{cin}, p.size(), p.begin());
    sort(p.begin(), p.end(), greater<int>{});
    cout << accumulate(p.cbegin(), p.cend(), make_pair(0LL, 0LL),
                       [](pair<long long, long long> const& r, int const& pi) {
                         return make_pair(r.first + 1LL,
                                          (r.second + max(0LL, pi - r.first)) %
                                              1'000'000'007LL);
                       })
                .second
         << '\n';
  }
  return 0;
}
