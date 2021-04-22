/* Problem flatten-a-multilevel-doubly-linked-list
 * https://www.leetcode.com/problems/flatten-a-multilevel-doubly-linked-list
 */

#include <stack>

// Definition for a Node.
class Node {
 public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

class Solution {
 public:
  Node* flatten(Node* const head, std::stack<Node*> nexts = {}) {
    if (head) {
      if (head->child) {
        if (head->next) nexts.push(head->next);
        head->next = head->child;
        head->next->prev = head;
        head->child = nullptr;
      } else if (!head->next && !nexts.empty()) {
        head->next = nexts.top();
        head->next->prev = head;
        nexts.pop();
      }
      flatten(head->next, nexts);
    }
    return head;
  }
};
