/* Problemset 894 - Problem A
 * https://codeforces.com/problemset/problem/894/A
 */

#include <iostream>
#include <iterator>
#include <numeric>
#include <tuple>

using namespace std;

int main() {
  cout << get<2>(accumulate(istream_iterator<char>(cin),
                            istream_iterator<char>(), make_tuple(0, 0, 0),
                            [](tuple<int, int, int> ans, char const c) {
                              if (c == 'Q') {
                                get<2>(ans) += get<1>(ans);
                                get<0>(ans) += 1;
                              } else if (c == 'A') {
                                get<1>(ans) += get<0>(ans);
                              }
                              return ans;
                            }))
       << '\n';
}
