/* Problem counting-elements
 * https://www.leetcode.com/problems/counting-elements
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int countElements(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int sol = 0, prev = -2, cnt = 0;
    for (auto const i : arr) {
      sol += (cnt + 1) * int{i == prev + 1};
      cnt = int{i == prev} * (cnt + 1);
      prev = i;
    }
    return sol;
  }
};
