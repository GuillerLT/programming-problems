/* Problem partition-list
 * https://www.leetcode.com/problems/partition-list
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int const x) : val(x), next(nullptr) {}
  ListNode(int const x, ListNode* const next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int const target) {
    ListNode begin_l{0, nullptr}, begin_r{0, nullptr};
    ListNode *end_l{&begin_l}, *end_r{&begin_r};
    for (; head; head = head->next) {
      ListNode*& ptr = (head->val < target) ? end_l : end_r;
      ptr = ptr->next = head;
    }
    end_l->next = begin_r.next;
    end_r->next = nullptr;
    return begin_l.next;
  }
};
