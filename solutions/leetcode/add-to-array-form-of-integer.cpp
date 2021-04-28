/* Problem add-to-array-form-of-integer
 * https://www.leetcode.com/problems/add-to-array-form-of-integer
 */

#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
    std::for_each(std::rbegin(num), std::rend(num),
                  [&k](int& n) {
                    n += k % 10;
                    k = k / 10 + n / 10;
                    n %= 10;
                  });
    for (; k > 0; k /= 10) num.insert(std::begin(num), k % 10);
    return num;
  }
};
