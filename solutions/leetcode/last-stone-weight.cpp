/* Problem last-stone-weight
 * https://www.leetcode.com/problems/last-stone-weight
 */

#include <queue>

using namespace std;

class Solution {
 public:
  int lastStoneWeight(vector<int>const& stones) {
    priority_queue<int> pq(stones.cbegin(), stones.cend());
    while(pq.size() > 1) {
      int const stone1 = pq.top();
      pq.pop();
      int const stone2 = pq.top();
      pq.pop();
      if(stone1 > stone2) pq.push(stone1-stone2);
    }
    return pq.empty() ? 0 : pq.top();
  }
};
