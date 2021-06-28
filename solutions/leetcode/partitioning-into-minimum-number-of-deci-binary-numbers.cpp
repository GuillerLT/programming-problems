/* Problem partitioning-into-minimum-number-of-deci-binary-numbers
 * https://www.leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers
 */

#include <numeric>
#include <string>

class Solution {
 public:
  static int minPartitions(std::string const n) {
    return static_cast<int>(
        std::reduce(std::begin(n), std::end(n), '1',
                    [](char const c1, char const c2) {
                      return std::max(c1, c2);
                    }) -
        '0');
  }
};