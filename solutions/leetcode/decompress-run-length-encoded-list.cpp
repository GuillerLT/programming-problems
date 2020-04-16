/* Problem decompress-run-length-encoded-list
 * https://www.leetcode.com/problems/decompress-run-length-encoded-list
 */

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> ans;
    for (size_t i = 0; i < nums.size(); i += 2) {
      fill_n(back_insert_iterator<vector<int>>(ans), nums[i], nums[i + 1]);
    }
    return ans;
  }
};
