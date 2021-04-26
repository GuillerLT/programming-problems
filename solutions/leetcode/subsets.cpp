#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int> const& nums, size_t i = 0) {
    if (i < nums.size()) {
      std::vector<std::vector<int>> ans{subsets(nums, i + 1)};
      size_t const s = ans.size();
      for (size_t j = 0; j < s; ++j) {
        std::vector<int> v{ans[j]};
        v.push_back(nums[nums.size() - 1 - i]);
        ans.push_back(std::move(v));
      }
      return ans;
    } else {
      return {{}};
    }
  }
};
