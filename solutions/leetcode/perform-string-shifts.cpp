/* Problem perform-string-shifts
 * https://www.leetcode.com/problems/perform-string-shifts
 */

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string stringShift(string s, vector<vector<int>> const& shift) {
    size_t const n = s.size();
    rotate(s.begin(),
           s.begin() + accumulate(shift.cbegin(), shift.cend(), 0,
                                  [n](int const r, vector<int> const& i) {
                                    return (r + (i[0] ? (n - i[1]) : i[1])) % n;
                                  }),
           s.end());
    return s;
  }
};
