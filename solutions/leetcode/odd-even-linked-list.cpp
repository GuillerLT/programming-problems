/* Problem odd-even-linked-list
 * https://www.leetcode.com/problems/odd-even-linked-list
 */

#include <array>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *oddEvenList(ListNode *head) {
    ListNode begin_odd, begin_even;
    std::array<ListNode *, 2> end{&begin_odd, &begin_even};
    for (bool even{false}; head; head = head->next, even ^= 1) {
      end[even] = end[even]->next = head;
    }
    end[0]->next = begin_even.next;
    end[1]->next = nullptr;
    return begin_odd.next;
  }
};
