/* Problem leftmost-column-with-at-least-a-one
 * https://www.leetcode.com/problems/leftmost-column-with-at-least-a-one
 */

#include <limits>
#include <vector>

using namespace std;

class BinaryMatrix {
 public:
  int get(int x, int y);
  vector<int> dimensions();
};

class Solution {
 public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    int const m = binaryMatrix.dimensions().front(),
              n = binaryMatrix.dimensions().back();
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < m; ++i) {
      int l = 0, r = n;
      while (l < r) {
        int const m = l + (r - l) / 2;
        if (binaryMatrix.get(i, m)) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      ans = min(ans, l);
    }
    if (ans == n) ans = -1;
    return ans;
  }
};
