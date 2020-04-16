/* Problem find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree
 * https://www.leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree
 */

#include <numeric>
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
  enum dir { left, right };
  pair<vector<dir>, bool> getDir(TreeNode const* const original,
                                 TreeNode const* const target) {
    if (original == nullptr) {
      return make_pair(vector<dir>{}, false);
    } else if (original == target) {
      // Found
      return make_pair(vector<dir>{}, true);
    } else {
      pair<vector<dir>, bool> ans;
      // Search left
      ans = getDir(original->left, target);
      if (ans.second) {
        ans.first.push_back(left);
        return ans;
      }
      // Search right
      ans = getDir(original->right, target);
      if (ans.second) {
        ans.first.push_back(right);
        return ans;
      }
      // Not found
      return make_pair(vector<dir>{}, false);
    }
  }

 public:
  TreeNode* getTargetCopy(TreeNode const* const original, TreeNode* cloned,
                          TreeNode const* const target) {
    auto const dirs = getDir(original, target).first;
    return accumulate(dirs.crbegin(), dirs.crend(), cloned,
                      [](TreeNode* const ans, dir const d) {
                        switch (d) {
                          case left:
                            return ans->left;
                          case right:
                            return ans->right;
                        }
                      });
  }
};
