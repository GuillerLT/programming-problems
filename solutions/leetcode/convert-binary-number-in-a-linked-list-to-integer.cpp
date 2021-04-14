/* Problem convert-binary-number-in-a-linked-list-to-integer
 * https://www.leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
 */

#include <utility>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 private:
  std::pair<int, int> getDecimalValue_impl(ListNode const* const head) {
    if (!head) {
      return {0, 0};
    } else {
      auto const [ans, exp]{getDecimalValue_impl(head->next)};
      return {ans + (head->val << exp), exp + 1};
    }
  }

 public:
  int getDecimalValue(ListNode* const head) {
    return getDecimalValue_impl(head).first;
  }
};
