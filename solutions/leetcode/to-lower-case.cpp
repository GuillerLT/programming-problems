/* Problem to-lower-case
 * https://www.leetcode.com/problems/to-lower-case
 */

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  string toLowerCase(string& str) {
    transform(str.cbegin(), str.cend(), str.begin(),
              [](char const c) { return tolower(c); });
    return str;
  }
};
