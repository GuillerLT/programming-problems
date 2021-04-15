/* Problem pseudo-palindromic-paths-in-a-binary-tree
 * https://www.leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree
 */

#include <bitset>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x = 0, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int pseudoPalindromicPaths(TreeNode *root, std::bitset<10> bs = {}) {
    bs.flip(root->val);
    if (!root->left && !root->right) {
      return bs.count() <= 1;
    } else {
      int ans{0};
      if (root->left) ans += pseudoPalindromicPaths(root->left, bs);
      if (root->right) ans += pseudoPalindromicPaths(root->right, bs);
      return ans;
    }
  }
};
