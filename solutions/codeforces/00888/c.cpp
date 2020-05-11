/* Problemset 888 - Problem C
 * https://codeforces.com/problemset/problem/888/C
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  vector<vector<int>> pos('z' - 'a' + 1);
  for (int i = 0; i < s.size(); ++i) {
    pos[s[i] - 'a'].emplace_back(i + 1);
  }
  transform(pos.begin(), pos.end(), pos.begin(),
            [n = s.size() + 1](vector<int>& p) {
              p.emplace_back(n);
              adjacent_difference(p.cbegin(), p.cend(), p.begin());
              return move(p);
            });
  cout << accumulate(pos.cbegin(), pos.cend(), s.size(),
                     [](int const ans, vector<int> const& p) {
                       return min(ans, *max_element(p.cbegin(), p.cend()));
                     })
       << endl;
  return 0;
}
