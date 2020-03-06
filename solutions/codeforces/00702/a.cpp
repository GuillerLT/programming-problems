/* Problemset 702 - Problem A
 * https://codeforces.com/problemset/problem/702/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <tuple>

using namespace std;

int main() {
  // tuple<previous value, max_cnt, current_cnt>
  auto f = [](tuple<int, int, int> const t, int const i) {
    if (i > get<0>(t)) {
      return make_tuple(i, get<1>(t), get<2>(t) + 1);
    } else {
      return make_tuple(i, max(get<1>(t), get<2>(t)), 1);
    }
  };
  auto const t =
      accumulate(next(istream_iterator<int>(cin)), istream_iterator<int>(),
                 make_tuple(numeric_limits<int>::max(), 1, 0), f);
  cout << max(get<1>(t), get<2>(t)) << '\n';
  return 0;
}
