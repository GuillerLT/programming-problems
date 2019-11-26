#include <iostream>
#include <tuple>
using namespace std;

tuple<int, int, int> sol(string const& s, int const l, int const r) {
  if (l == r) {
    return ((s[l] == '(') ? make_tuple(0, 1, 0) : make_tuple(0, 0, 1));
  } else {
    int const m = l + (r - l) / 2;
    auto t1 = sol(s, l, m);
    auto t2 = sol(s, m + 1, r);
    int const c = min(get<1>(t1), get<2>(t2));
    return make_tuple(get<0>(t1) + get<0>(t2) + c,
                      get<1>(t1) + get<1>(t2) - c,
                      get<2>(t1) + get<2>(t2) - c);
  }
}

int main() {
  string s;
  cin >> s;
  cout << 2 * get<0>(sol(s, 0, s.size() - 1)) << '\n';
  return 0;
}
