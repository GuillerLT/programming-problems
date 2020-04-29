/* Problemset 327 - Problem A
 * https://codeforces.com/problemset/problem/327/A
 */

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int ones = 0, flip = 0, cur = 0;
  for (size_t i = *istream_iterator<size_t>(cin); i > 0; --i) {
    int const ai = *istream_iterator<int>(cin);
    ones += ai;
    cur = max(0, cur - (2 * ai - 1));
    flip = max(flip, cur);
  }
  cout << ones + flip - int{flip == 0} << '\n';
  return 0;
}
