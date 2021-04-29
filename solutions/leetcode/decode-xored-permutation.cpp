/* Problem decode-xored-permutation
 * https://www.leetcode.com/problems/decode-xored-permutation
 */

#include <functional>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> decode(std::vector<int>& encoded) {
    int dn{0};
    for (int i = encoded.size() + 1; i >= 1; i -= 1) dn ^= i;
    for (int i = encoded.size() - 2; i >= 0; i -= 2) dn ^= encoded[i];
    encoded.push_back(dn);
    for (int i = encoded.size() - 2; i >= 0; i -= 1) encoded[i] ^= encoded[i + 1];
    return encoded;
  }
};
