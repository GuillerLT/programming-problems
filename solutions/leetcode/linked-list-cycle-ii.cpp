/* Problem linked-list-cycle-ii
 * https://www.leetcode.com/problems/linked-list-cycle-ii
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(const int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *const head) const {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) break;
    }
    if (fast == nullptr || fast->next == nullptr)
      return nullptr;
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};
