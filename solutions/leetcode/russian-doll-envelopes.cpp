/* Problem russian-doll-envelopes
 * https://www.leetcode.com/problems/russian-doll-envelopes
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(begin(envelopes), end(envelopes),
         [](vector<int> const& e1, vector<int> const& e2) {
           return e1.front() < e2.front() ||
                  !(e2.front() < e1.front()) && e1.back() > e2.back();
         });
    // O(n^2)
    for (auto it1 = begin(envelopes); it1 != cend(envelopes); ++it1) {
      it1->push_back(1);
      for (auto it2 = begin(envelopes); it2 != it1; ++it2) {
        it1->back() =
            max(it1->back(), it2->back() * ((*it2)[1] < (*it1)[1] ? 1 : 0) + 1);
      }
    }
    return max_element(cbegin(envelopes), cend(envelopes),
                       [](vector<int> const& e1, vector<int> const& e2) {
                         return e1.back() < e2.back();
                       })
        ->back();
  }
};
