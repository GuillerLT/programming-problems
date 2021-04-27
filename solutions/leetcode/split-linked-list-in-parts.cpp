/* Problem split-linked-list-in-parts
 * https://www.leetcode.com/problems/split-linked-list-in-parts
 */

#include <utility>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 private:
  int listSize(ListNode *const root) {
    return root ? listSize(root->next) + 1 : 0;
  }

  ListNode *extract(ListNode *root, int const n) {
    return n > 1 ? extract(root->next, n - 1) : std::exchange(root->next, nullptr);
  }

 public:
  std::vector<ListNode *> splitListToParts(ListNode *root, int const k) {
    int const size{listSize(root)};
    int const d{size / k};
    int r{size % k};
    std::vector<ListNode *> ans;
    while (root)
      ans.push_back(std::exchange(root, extract(root, d + std::max(0, std::min(1, r--)))));
    ans.resize(k, nullptr);
    return ans;
  }
};
