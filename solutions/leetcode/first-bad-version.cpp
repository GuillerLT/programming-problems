/* Problem first-bad-version
 * https://www.leetcode.com/problems/first-bad-version
 */

bool isBadVersion(int version);

class Solution {
 private:
  long long int binary_search(long long int const first, long long int const last) {
    if (first != last) {
      long long int const mid = first + (last - first) / 2;
      if (isBadVersion(mid)) {
        return binary_search(first, mid);
      } else {
        return binary_search(mid + 1, last);
      }
    } else {
      return last;
    }
  }

 public:
  int firstBadVersion(int const n) { return binary_search(1LL, n + 1LL); }
};
