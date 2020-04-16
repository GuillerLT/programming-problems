/* Problem jewels-and-stones
 * https://www.leetcode.com/problems/jewels-and-stones
 */

#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

class Solution {
 public:
  int numJewelsInStones(string j, string const& s) {
    sort(j.begin(), j.end());
    return accumulate(s.cbegin(), s.cend(), 0, [&j](int const r, char const c) {
      return r + int{binary_search(j.cbegin(), j.cend(), c)};
    });
  }
};
