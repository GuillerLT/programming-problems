/* Problem defanging-an-ip-address
 * https://www.leetcode.com/problems/defanging-an-ip-address
 */

#include <numeric>
#include <string>

using namespace std;

class Solution {
 public:
  string defangIPaddr(string address) {
    return accumulate(address.cbegin(), address.cend(), string{},
                      [](string const s, char const c) {
                        return s + (c == '.' ? string{"[.]"} : string{c});
                      });
  }
};
