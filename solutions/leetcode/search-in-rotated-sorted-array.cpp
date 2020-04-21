/* Problem search-in-rotated-sorted-array
 * https://www.leetcode.com/problems/search-in-rotated-sorted-array
 */

#include <vector>

using namespace std;

class Solution {
 private:
  pair<bool, vector<int>::const_iterator> rotation_point(
      vector<int>::const_iterator const first,
      vector<int>::const_iterator const last) {
    ptrdiff_t const dist = distance(first, last);
    if (dist <= 1 || *first < *prev(last)) {
      return make_pair(true, first);
    } else {
      vector<int>::const_iterator const mid = first + dist / 2;
      auto const right = rotation_point(mid, last);
      if (right.first && *prev(mid) < *mid) {
        return make_pair(false, rotation_point(first, mid).second);
      } else {
        return make_pair(false, right.second);
      }
    }
  }

 public:
  int search(vector<int> const& nums, int const target) {
    auto const mid = rotation_point(nums.cbegin(), nums.cend()).second;
    auto const left = lower_bound(nums.cbegin(), mid, target);
    if (left != nums.cend() && *left == target) return left - nums.cbegin();
    auto const right = lower_bound(mid, nums.cend(), target);
    if (right != nums.cend() && *right == target) return right - nums.cbegin();
    return -1;
  }
};
