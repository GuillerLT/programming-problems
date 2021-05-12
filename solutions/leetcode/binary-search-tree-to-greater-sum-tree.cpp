/* Problem binary-search-tree-to-greater-sum-tree
 * https://www.leetcode.com/problems/binary-search-tree-to-greater-sum-tree
 */

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
  static int bstToGst_impl(TreeNode *const root, int const acum = 0) {
    int const r{root->right ? bstToGst_impl(root->right, acum) : 0};
    int const l{root->left ? bstToGst_impl(root->left, acum + root->val + r) : 0};
    int const t{l + root->val + r};
    root->val += acum + r;
    return t;
  }

 public:
  static TreeNode *bstToGst(TreeNode *const root) {
    bstToGst_impl(root);
    return root;
  }
};
