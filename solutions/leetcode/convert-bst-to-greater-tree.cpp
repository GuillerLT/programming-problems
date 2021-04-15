/* Problem convert-bst-to-greater-tree
 * https://www.leetcode.com/problems/convert-bst-to-greater-tree
 */

#include <utility>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x = 0, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(x), left(left), right(right) {}
};

class Solution {
 private:
  int convertBST_impl(TreeNode *root, int const g = 0) {
    if (root) {
      int const r{convertBST_impl(root->right, g)};
      int const l{convertBST_impl(root->left, g + r + root->val)};
      return l + std::exchange(root->val, root->val + r + g) + r;
    } else {
      return 0;
    }
  }

 public:
  TreeNode *convertBST(TreeNode *root) {
    convertBST_impl(root);
    return root;
  }
};
