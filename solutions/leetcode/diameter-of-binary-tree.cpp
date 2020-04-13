/* Problem diameter-of-binary-tree
 * https://www.leetcode.com/problems/diameter-of-binary-tree
 */

#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 private:
  pair<int, int> depth_and_diameter(TreeNode const *const root) {
    if (root == nullptr) {
      return make_pair(0, 0);
    } else {
      auto const l = depth_and_diameter(root->left),
                 r = depth_and_diameter(root->right);
      return make_pair(max(l.first, r.first) + 1,
                       max({l.first + r.first, l.second, r.second}));
    }
  }

 public:
  int diameterOfBinaryTree(TreeNode const *const root) {
    return depth_and_diameter(root).second;
  }
};
