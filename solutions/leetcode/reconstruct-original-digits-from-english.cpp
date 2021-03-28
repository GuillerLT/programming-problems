/* Problem reconstruct-original-digits-from-english
 * https://www.leetcode.com/problems/reconstruct-original-digits-from-english
 */

#include <array>
#include <string>

using namespace std;

class Solution {
 public:
  string originalDigits(string const s) {
    array<int, 26> freq{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (char const c : s) ++freq[c - 'a'];
    array<int, 10> ans;
    // 0
    ans[0] = freq['z' - 'a'];
    freq['z' - 'a'] -= ans[0];
    freq['o' - 'a'] -= ans[0];
    // 2
    ans[2] = freq['w' - 'a'];
    freq['t' - 'a'] -= ans[2];
    freq['o' - 'a'] -= ans[2];
    // 4
    ans[4] = freq['u' - 'a'];
    freq['f' - 'a'] -= ans[4];
    freq['o' - 'a'] -= ans[4];
    // 6
    ans[6] = freq['x' - 'a'];
    freq['s' - 'a'] -= ans[6];
    freq['x' - 'a'] -= ans[6];
    // 8
    ans[8] = freq['g' - 'a'];
    freq['t' - 'a'] -= ans[8];
    // 1
    ans[1] = freq['o' - 'a'];
    freq['n' - 'a'] -= ans[1];
    // 3
    ans[3] = freq['t' - 'a'];
    // 5
    ans[5] = freq['f' - 'a'];
    // 7
    ans[7] = freq['s' - 'a'];
    freq['n' - 'a'] -= ans[7];
    // 9
    ans[9] = freq['n' - 'a'] / 2;
    // str
    string str;
    for (char c = '0'; c <= '9'; ++c) {
      str.insert(str.end(), ans[c - '0'], c);
    }
    return str;
  }
};
