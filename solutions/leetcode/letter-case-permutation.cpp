/* Problem letter-case-permutation
 * https://www.leetcode.com/problems/letter-case-permutation
 */

#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> letterCasePermutation(std::string_view const s, std::vector<std::string> v = {""}) {
    if (s.empty()) {
      return v;
    } else {
      if (s[0] >= '0' && s[0] <= '9') {
        std::transform(std::cbegin(v), std::cend(v), std::begin(v),
                       [c = s[0]](std::string s) { return s + c; });
      } else {
        std::vector<std::string> aux(std::cbegin(v), std::cend(v));
        std::transform(std::cbegin(v), std::cend(v), std::begin(v),
                       [l = static_cast<char>(std::tolower(s[0]))](std::string s) { return s + l; });
        std::transform(std::cbegin(aux), std::cend(aux), std::begin(aux),
                       [u = static_cast<char>(std::toupper(s[0]))](std::string s) { return s + u; });
        std::move(std::begin(aux), std::end(aux), std::back_inserter(v));
      }
      return letterCasePermutation(s.substr(1), v);
    }
  }
};
