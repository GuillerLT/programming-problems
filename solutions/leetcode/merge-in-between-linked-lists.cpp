/* Problem merge-in-between-linked-lists
 * https://www.leetcode.com/problems/merge-in-between-linked-lists
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 private:
  ListNode* advance(ListNode* it, int n) {
    for (; n > 0; --n) it = it->next;
    return it;
  }
  ListNode* last(ListNode* const it) {
    return it->next == nullptr ? it : last(it->next);
  }

 public:
  ListNode* mergeInBetween(ListNode* list1, int const a, int const b,
                           ListNode* list2) {
    ListNode* l{advance(list1, a - 1)};
    last(list2)->next = advance(l, b - a + 2);
    l->next = list2;
    return list1;
  }
};
