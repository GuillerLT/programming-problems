/* Problem xor-queries-of-a-subarray
 * https://www.leetcode.com/problems/xor-queries-of-a-subarray
 */

#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> xorQueries(std::vector<int>& arr,
                              std::vector<std::vector<int>> const& queries) {
    std::inclusive_scan(std::cbegin(arr), std::cend(arr), std::begin(arr),
                        std::bit_xor{});
    arr.insert(arr.begin(), 0);
    std::vector<int> ans;
    std::transform(std::cbegin(queries), std::cend(queries),
                   std::back_inserter(ans),
                   [&arr](std::vector<int> const& query) {
                     return arr[query.front()] ^ arr[query.back() + 1];
                   });
    return ans;
  }
};
