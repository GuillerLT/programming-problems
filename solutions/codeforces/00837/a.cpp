/* Problemset 837 - Problem A
 * https://codeforces.com/problemset/problem/837/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;

int main() {
  cout << accumulate(
              istream_iterator<string>(cin), istream_iterator<string>(), 0,
              [](int const n, string const s) {
                return max(n, static_cast<int>(count_if(
                                  s.cbegin(), s.cend(), [](char const c) {
                                    return c >= 'A' & c <= 'Z';
                                  })));
              })
       << '\n';
  return 0;
}
