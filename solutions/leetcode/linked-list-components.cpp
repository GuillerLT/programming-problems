/* Problem linked-list-components
 * https://www.leetcode.com/problems/linked-list-components
 */

#include <set>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}
};

class Solution {
 public:
  int numComponents(ListNode* head, std::vector<int> const& G) {
    std::set<int> s{std::begin(G), std::end(G)};
    int ans{0};
    for (bool connected{false}; head; head = head->next) {
      bool const c{s.count(head->val) > 0};
      ans += c && !connected;
      connected = c;
    }
    return ans;
  }
};
