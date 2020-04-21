/* Problem valid-parenthesis-string
 * https://www.leetcode.com/problems/valid-parenthesis-string
 */

#include <numeric>
#include <string>

using namespace std;

class Solution {
 public:
  bool checkValidString(string const& s) {
    auto const min_max = accumulate(
        s.cbegin(), s.end(), make_pair(0, 0),
        [](pair<int, int> const min_max, char const c) {
          if (min_max.second < 0) return min_max;
          switch (c) {
            case '(':
              return make_pair(min_max.first + 1, min_max.second + 1);
            case ')':
              return make_pair(max(0, min_max.first - 1), min_max.second - 1);
            default:
              return make_pair(max(0, min_max.first - 1), min_max.second + 1);
          }
        });
    return min_max.first == 0 && min_max.second >= 0;
  }
};
