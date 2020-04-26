/* Problem all-elements-in-two-binary-search-trees
 * https://www.leetcode.com/problems/all-elements-in-two-binary-search-trees
 */

#include <stack>
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
  void first(stack<TreeNode const*>& stack) {
    while (stack.top()->left != nullptr) {
      stack.emplace(stack.top()->left);
    }
  }
  void next(stack<TreeNode const*>& stack) {
    if (stack.top()->right != nullptr) {
      stack.top() = stack.top()->right;
      first(stack);
    } else {
      stack.pop();
    }
  }

 public:
  vector<int> getAllElements(TreeNode const* const root1,
                             TreeNode const* const root2) {
    stack<TreeNode const*> s1, s2;
    if (root1 != nullptr) {
      s1.emplace(root1);
      first(s1);
    }
    if (root2 != nullptr) {
      s2.emplace(root2);
      first(s2);
    }
    vector<int> ans;
    while (true) {
      if (s1.empty() && s2.empty()) {
        return ans;
      } else if (s1.empty()) {
        ans.emplace_back(s2.top()->val);
        next(s2);
      } else if (s2.empty()) {
        ans.emplace_back(s1.top()->val);
        next(s1);
      } else if (s1.top()->val < s2.top()->val) {
        ans.emplace_back(s1.top()->val);
        next(s1);
      } else {
        ans.emplace_back(s2.top()->val);
        next(s2);
      }
    }
  }
};
