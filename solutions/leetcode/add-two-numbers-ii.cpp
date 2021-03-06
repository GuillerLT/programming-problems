/* Problem add-two-numbers-ii
 * https://www.leetcode.com/problems/add-two-numbers-ii
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
  ListNode* reverse(ListNode* const curr, ListNode* const prev = nullptr) {
    return curr ? reverse(std::exchange(curr->next, prev), curr) : prev;
  }

 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode head;
    ListNode* last{&head};
    int remainder = 0;
    while (l1 || l2) {
      int const sum{remainder +
                    (l1 ? std::exchange(l1, l1->next)->val : 0) +
                    (l2 ? std::exchange(l2, l2->next)->val : 0)};
      remainder = sum / 10;
      last = last->next = new ListNode(sum % 10);
    }
    if (remainder) last = last->next = new ListNode(remainder);
    return reverse(head.next);
  }
};
