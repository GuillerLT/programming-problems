#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> processQueries(vector<int> const& queries, int const m) {
    vector<int> ans(queries.size()), aux(m + 1);
    iota(aux.begin(), aux.end(), -1);
    for (size_t i = 0; i < queries.size(); ++i) {
      int const a = aux[queries[i]];
      transform(aux.cbegin(), aux.cend(), aux.begin(),
                [a](int const j) { return j + int{j < a}; });
      ans[i] = a;
      aux[queries[i]] = 0;
    }
    return ans;
  }
};
