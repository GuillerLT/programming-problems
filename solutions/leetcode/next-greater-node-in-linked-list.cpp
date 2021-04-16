/* Problem next-greater-node-in-linked-list
 * https://www.leetcode.com/problems/next-greater-node-in-linked-list
 */

#include <map>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

class Solution {
 public:
  std::vector<int> nextLargerNodes(ListNode *head) {
    std::vector<int> ans;
    std::map<int, std::vector<int>> aux;
    for (; head; head = head->next) {
      auto const [end, inserted]{aux.insert({head->val, {}})};
      end->second.push_back(ans.size());
      for (auto it = aux.begin(); it != end; it = aux.erase(it)) {
        for (int const index : it->second) {
          ans[index] = head->val;
        }
      }
      ans.push_back(0);
    }
    return ans;
  }
};
