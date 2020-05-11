/* Problemset 888 - Problem B
 * https://codeforces.com/problemset/problem/888/B
 */

#include <iostream>
#include <iterator>
#include <numeric>
#include <tuple>

using namespace std;

int main() {
  size_t const n = *istream_iterator<size_t>(cin);
  string const s = *istream_iterator<string>(cin);
  auto const total = accumulate(
      s.cbegin(), s.cend(), make_tuple(0, 0, 0, 0),
      [](tuple<int, int, int, int> const t, char const c) {
        switch (c) {
          case 'U':
            return make_tuple(get<0>(t) + 1, get<1>(t), get<2>(t), get<3>(t));
          case 'D':
            return make_tuple(get<0>(t), get<1>(t) + 1, get<2>(t), get<3>(t));
          case 'L':
            return make_tuple(get<0>(t), get<1>(t), get<2>(t) + 1, get<3>(t));
          case 'R':
            return make_tuple(get<0>(t), get<1>(t), get<2>(t), get<3>(t) + 1);
        }
      });
  cout << 2 * min(get<0>(total), get<1>(total)) +
          2 * min(get<2>(total), get<3>(total))
       << '\n';
  return 0;
}
