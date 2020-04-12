/* Problem backspace-string-compare
 * https://www.leetcode.com/problems/backspace-string-compare
 */

#include <numeric>
#include <string>

using namespace std;

class Solution {
 private:
  char prevChar(string &s, int &i) {
    if (i < 0) {
      return char{0};
    } else if (s[i] != '#') {
      return s[i];
    } else {
      --i;
      for (size_t cnt = 1; cnt && i >= 0;--i) {
        if (s[i] == '#') {
          ++cnt;
        } else {
          --cnt;
        }
      }
      return prevChar(s, i);
    }
  }

 public:
  bool backspaceCompare(string s, string t) {
    for (int i = s.size() - 1, j = t.size() - 1;; --i, --j) {
      char const c = prevChar(s, i), d = prevChar(t, j);
      if (c != d) {
        return false;
      } else if (c == char{0}) {
        return true;
      }
    }
  }
};
