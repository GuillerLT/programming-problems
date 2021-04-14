/* Problem delete-node-in-a-linked-list
 * https://www.leetcode.com/problems/delete-node-in-a-linked-list
 */

struct ListNode {
  int val;
  ListNode* next;
};

class Solution {
 public:
  void deleteNode(ListNode* const node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
