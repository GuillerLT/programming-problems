/* Problem construct-binary-search-tree-from-preorder-traversal
 * https://www.leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal
 */

#include <limits>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 private:
  pair<size_t, TreeNode*> bstFromPreorder(
      vector<int> const& preorder, size_t const index,
      int const limit = numeric_limits<int>::max()) {
        if (index >= preorder.size() || preorder[index] > limit) {
          return make_pair(index, nullptr);
        } else {
          auto left = bstFromPreorder(preorder, index+1, preorder[index]);
          auto right = bstFromPreorder(preorder, left.first, limit);
          TreeNode * const ans = new TreeNode(preorder[index]);
          ans->left = left.second;
          ans->right = right.second;
          return make_pair(right.first, ans);
        }
      }

 public:
  TreeNode* bstFromPreorder(vector<int> const& preorder) {
    return bstFromPreorder(preorder, 0).second;
  }
};
