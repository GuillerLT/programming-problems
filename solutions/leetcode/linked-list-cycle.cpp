/* Problem linked-list-cycle
 * https://www.leetcode.com/problems/linked-list-cycle
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(const int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *const head) const {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true;
    }
    return false;
  }
};
