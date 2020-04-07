/* Problem group-anagrams
 * https://www.leetcode.com/problems/group-anagrams
 */

#include <algorithm>
#include <array>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

struct cmp {
  bool operator()(array<size_t, 26> const& a1,
                  array<size_t, 26> const& a2) const {
    for (size_t i = 0; i < 26; ++i)
      if (a1[i] != a2[i]) return a1[i] < a2[i];
    return false;
  }
};

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<array<size_t, 26>, vector<string>, cmp> m;
    for (auto& str : strs) {
      array<size_t, 26> k;
      k.fill(size_t{0});
      for_each(str.cbegin(), str.cend(), [&k](char c) { ++k[c - 'a']; });
      m[move(k)].emplace_back(move(str));
    }
    vector<vector<string>> sol;
    for (auto& it : m) {
      sol.emplace_back(move(it.second));
    }
    return sol;
  }
};
