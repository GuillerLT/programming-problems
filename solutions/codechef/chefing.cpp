#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int i;
  cin >> i;
  while (--i >= 0) {
    vector<string> vs;
    int sis = 0;
    int j;
    cin >> j;
    while (--j >= 0) {
      string s;
      cin >> s;
      vs.push_back(s);
    }
    sort(vs.begin(), vs.end(), [](string const& s1, string const& s2) -> bool {
      return s1.size() < s2.size();
    });
    bitset<((size_t)'z' - (size_t)'a' + 1)> bs;
    for (char const& c : vs.front()) {
      size_t const k = (size_t)c - 'a';
      if (!bs.test(k)) {
        bs.set(k);
        bool si = true;
        for (size_t l = 1; l < vs.size(); ++l) {
          if (vs[l].find(c) == string::npos) {
            si = false;
            break;
          }
        }
        if (si) ++sis;
      }
    }
    cout << sis << '\n';
  }
  return 0;
}