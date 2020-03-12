/* Problemset 762 - Problem B
 * https://codeforces.com/problemset/problem/762/B
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  size_t nu, np, nb;
  cin >> nu >> np >> nb;
  int n;
  cin >> n;
  vector<int> pu, pp;
  while (--n >= 0) {
    int p;
    string s;
    cin >> p >> s;
    if (s.front() == 'U') {
      pu.push_back(p);
    } else {
      pp.push_back(p);
    }
  }
  sort(pu.begin(), pu.end());
  sort(pp.begin(), pp.end());
  size_t const ru = min(nu, pu.size());
  size_t const rp = min(np, pp.size());
  long long ans = 0;
  ans += accumulate(pu.cbegin(), pu.cbegin() + ru, 0LL);
  ans += accumulate(pp.cbegin(), pp.cbegin() + rp, 0LL);
  vector<int> pb;
  merge(pu.cbegin() + ru, pu.cend(), pp.cbegin() + rp, pp.cend(),
        back_insert_iterator<vector<int>>(pb));
  size_t const rb = min(nb, pb.size());
  ans += accumulate(pb.cbegin(), pb.cbegin() + rb, 0LL);
  cout << (ru + rp + rb) << ' ' << ans << '\n';
}
