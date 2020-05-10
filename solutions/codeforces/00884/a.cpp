/* Problemset 884 - Problem A
 * https://codeforces.com/problemset/problem/884/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
  istream_iterator<int> it(cin);
  int const n = *it;
  int t = *++it;
  cout << 1 + count_if(++it, istream_iterator<int>(),
                       [&t](int const ai) {
                         t -= 86400 - ai;
                         return t > 0;
                       })
       << '\n';
}
