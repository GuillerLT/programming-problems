/* Problem check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree
 * https://www.leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree
 */

#include <vector>

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
 public:
  bool isValidSequence(TreeNode const *root, vector<int> const &arr,
                       size_t const i = 0) {
    if (root == nullptr || root->val != arr[i]) return false;
    if (i + 1 == arr.size()) {
      return root->left == nullptr && root->right == nullptr;
    } else {
      return isValidSequence(root->left, arr, i + 1) ||
             isValidSequence(root->right, arr, i + 1);
    }
  }
};
