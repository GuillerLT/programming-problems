/* Problem longest-univalue-path
 * https://www.leetcode.com/problems/longest-univalue-path
 */

#include <tuple>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 private:
  static std::tuple<int, int, int> longestUnivaluePath_impl(TreeNode *const root) {
    if (root == nullptr) {
      return {1001, 0, 0};
    } else {
      auto const l{longestUnivaluePath_impl(root->left)};
      auto const r{longestUnivaluePath_impl(root->right)};
      int const v{root->val};
      int const s1{std::max(v == std::get<0>(l) ? get<1>(l) + 1 : 0,
                            v == std::get<0>(r) ? get<1>(r) + 1 : 0)};
      int const s2{v == std::get<0>(l) && v == std::get<0>(r) ? get<1>(l) + get<1>(r) + 2 : 0};
      return {v, s1, std::max({s2, get<1>(l), get<2>(l), get<1>(r), get<2>(r)})};
    }
  }

 public:
  static int longestUnivaluePath(TreeNode *const root) {
    auto const [v, s1, s2]{longestUnivaluePath_impl(root)};
    return std::max(s1, s2);
  }
};
