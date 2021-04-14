/* Problem swapping-nodes-in-a-linked-list
 * https://www.leetcode.com/problems/swapping-nodes-in-a-linked-list
 */

#include <algorithm>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}
};

class Solution {
 private:
  int count(ListNode* const it) { return it ? count(it->next) + 1 : 0; }
  ListNode* advance(ListNode* it, int n) {
    for (; n > 0; --n) {
      it = it->next;
    }
    return it;
  }

 public:
  ListNode* swapNodes(ListNode* head, int const k) {
    int const n{count(head)};
    int const a{std::min(k, n - k + 1)};
    int const b{std::max(k, n - k + 1)};
    if (a != b) {
      ListNode* an{advance(head, a - 1)};
      ListNode* bn{advance(an, b - a)};
      std::swap(an->val, bn->val);
    }
    return head;
  }
};
