/* Problem partition-labels
 * https://www.leetcode.com/problems/partition-labels
 */

#include <array>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string const& s) {
    array<size_t, 26> last;
    for (size_t i = 0; i < s.size(); ++i) last[s[i] - 'a'] = i;
    vector<int> ans;
    for (size_t i = 0; i < s.size();) {
      size_t l = last[s[i] - 'a'];
      for (int j = i + 1; j < l; ++j) {
        l = max(l, last[s[j] - 'a']);
      }
      ans.emplace_back(l - i + 1);
      i = l + 1;
    }
    return ans;
  }
};
