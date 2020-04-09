/* Problem middle-of-the-linked-list
 * https://www.leetcode.com/problems/middle-of-the-linked-list
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    int size = 1;
    for (ListNode* next = head->next; next; next = next->next) {
      ++size;
    }
    size /= 2;
    while (size--) {
      head = head->next;
    }
    return head;
  }
};
