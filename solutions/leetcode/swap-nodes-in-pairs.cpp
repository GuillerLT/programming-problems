#include <utility>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* const head) {
    if (head) {
      if (head->next) {
        ListNode* const aux{std::exchange(head->next, swapPairs(head->next->next))};
        aux->next = head;
        return aux->next;
      }
    }
    return head;
  }
};
