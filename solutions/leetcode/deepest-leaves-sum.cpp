/* Problem deepest-leaves-sum
 * https://www.leetcode.com/problems/deepest-leaves-sum
 */

#include <tuple>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 private:
  pair<int, int> aux(TreeNode const *const node) {
    if (node != nullptr) {
      auto const left = aux(node->left), right = aux(node->right);
      if (left.first == -1 && right.first == -1) {
        return make_pair(0, node->val);
      } else if (left.first > right.first) {
        return make_pair(left.first + 1, left.second);
      } else if (right.first > left.first) {
        return make_pair(right.first + 1, right.second);
      } else {
        return make_pair(left.first + 1, left.second + right.second);
      }
    } else {
      return make_pair(-1, 0);
    }
  }

 public:
  int deepestLeavesSum(TreeNode const *const root) { return aux(root).second; }
};