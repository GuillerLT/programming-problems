/* Problem group-the-people-given-the-group-size-they-belong-to
 * https://www.leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to
 */

#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    map<int, vector<vector<int>>> m;
    for (size_t i = 0; i < groupSizes.size(); ++i) {
      vector<vector<int>>& n = m[groupSizes[i]];
      if (n.empty() || n.back().size() == groupSizes[i]) {
        n.emplace_back();
      }
      n.back().emplace_back(i);
    }
    vector<vector<int>> ans;
    for (pair<int const, vector<vector<int>>>& n : m) {
      for (vector<int>& o : n.second) {
        ans.emplace_back(move(o));
      }
    }
    return ans;
  }
};
