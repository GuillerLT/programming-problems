/* Problem first-unique-number
 * https://www.leetcode.com/problems/first-unique-number
 */

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class FirstUnique {
  list<int> ans;
  unordered_map<int, list<int>::const_iterator> aux;

 public:
  FirstUnique(vector<int> const& nums) {
    for (int const value : nums) {
      add(value);
    }
  }

  int showFirstUnique() { return ans.empty() ? -1 : ans.front(); }

  void add(int const value) {
    auto const it = aux.find(value);
    if (it != aux.cend()) {
      if (aux[value] != ans.cend()) {
        ans.erase(aux[value]);
        aux[value] = ans.cend();
      }
    } else {
      aux[value] = ans.insert(ans.cend(), value);
    }
  }
};
