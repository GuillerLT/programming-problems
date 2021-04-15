/* Problem decode-xored-array
 * https://www.leetcode.com/problems/decode-xored-array
 */

#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> decode(std::vector<int>& encoded, int const first) {
    std::vector<int>& decoded{encoded};
    decoded.insert(std::begin(decoded), first);
    std::inclusive_scan(std::cbegin(encoded), std::cend(encoded),
                        std::begin(decoded),
                        [](int const a, int const b) { return a ^ b; });
    return decoded;
  }
};
