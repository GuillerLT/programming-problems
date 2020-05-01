/* Problem binary-tree-maximum-path-sum
 * https://www.leetcode.com/problems/binary-tree-maximum-path-sum
 */

#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  pair<int, int> aux(TreeNode const *const root) {
    if (root != nullptr) {
      pair<int, int> const left = aux(root->left), right = aux(root->right);
      return make_pair(max(0, max(left.first, right.first) + root->val),
                       max({root->val + left.first + right.first, left.second,
                            right.second}));
    } else {
      return make_pair(0, numeric_limits<int>::min());
    }
  }

 public:
  int maxPathSum(TreeNode const *const root) { return aux(root).second; }
};
