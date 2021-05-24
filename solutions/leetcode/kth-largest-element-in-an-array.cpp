/* Problem kth-largest-element-in-an-array
 * https://www.leetcode.com/problems/kth-largest-element-in-an-array
 */

#include <algorithm>
#include <vector>

class Solution {
 private:
  template <class It>
  static void nth_element(It const begin, It const nth, It const end) {
    // assert(begin < end);
    // assert(begin <= nth && nth <= end);
    It partition{std::prev(end)};
    for (It it{partition}; it != begin; --it) {
      if (*it > *begin) {
        std::iter_swap(it, partition--);
      }
    }
    std::iter_swap(begin, partition);
    if (nth < partition) {
      nth_element(begin, nth, partition);
    } else if (nth > partition) {
      nth_element(std::next(partition), nth, end);
    }
  }

 public:
  static int findKthLargest(std::vector<int>& nums, int const k) {
    auto const kth{std::end(nums) - k};
    nth_element(std::begin(nums), kth, std::end(nums));
    return *kth;
  }
};