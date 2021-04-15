/* Problem count-triplets-that-can-form-two-arrays-of-equal-xor
 * https://www.leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor
 */

#include <unordered_map>
#include <vector>

class Solution {
 public:
  int countTriplets(std::vector<int> const& arr) {
    int ans{0}, aux{0};
    std::unordered_map<int, std::vector<int>> mem{{0, {-1}}};
    for (size_t i = 0; i < arr.size(); ++i) {
      aux ^= arr[i];
      for (size_t const j : mem[aux]) {
        ans += i - j - 1;
      }
      mem[aux].push_back(i);
    }
    return ans;
  }
};
