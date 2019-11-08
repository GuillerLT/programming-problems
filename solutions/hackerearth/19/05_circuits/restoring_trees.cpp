#include <iostream>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

class cmp {
 public:
  bool operator()(tuple<int, int> const& t1, tuple<int, int> const& t2) const {
    return get<0>(t1) < get<0>(t2);
  }
};

void solve(int const& s, int const& f, int const& r,
           unordered_map<int, set<tuple<int, int>, cmp>> const& mem,
           vector<int>& aux) {
  if (f > s) {
    auto const& m = mem.find(f)->second.lower_bound(make_tuple(s, 0));
    aux[get<1>(*m)-1] = r;
    solve(get<0>(*m) + 1, f, get<1>(*m), mem, aux);
    solve(s, get<0>(*m), r, mem, aux);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> aux(n, 0);
  for (auto& v : aux) cin >> v;
  unordered_map<int, set<tuple<int, int>, cmp>> mem;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    mem[v].insert(make_tuple(aux[i], i + 1));
  }
  solve(0, n, 0, mem, aux);
  for (auto const& v : aux) cout << v << " ";
  cout << "\n" << flush;
  return 0;
}