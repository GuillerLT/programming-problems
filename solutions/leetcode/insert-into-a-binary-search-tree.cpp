/* Problem insert-into-a-binary-search-tree
 * https://www.leetcode.com/problems/insert-into-a-binary-search-tree
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* const root, int const val) {
    if (val < root->val) {
      if (root->left != nullptr) {
        insertIntoBST(root->left, val);
      } else {
        root->left = new TreeNode(val);
      }
    } else {
      if (root->right != nullptr) {
        insertIntoBST(root->right, val);
      } else {
        root->right = new TreeNode(val);
      }
    }
    return root;
  }
};