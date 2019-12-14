/* Contest SEPT19B - Problem CHEFINSQ
 * https://www.codechef.com/SEPT19B/problems/CHEFINSQ
 */

#include <iostream>
#include <map>

using namespace std;

int bc[51][51];

int sol(int k, map<int, int>& mii) {
  auto it = mii.begin();
  while (it->second < k) {
    k -= it->second;
    it++;
  }
  return bc[it->second][k];
}

int main() {
  for (int n = 1; n < 51; ++n) {
    bc[n][1] = n;
    for (int k = 2; k < n; ++k) {
      bc[n][k] = bc[n - 1][k] + bc[n - 1][k - 1];
    }
    bc[n][n] = 1;
  }
  int t;
  cin >> t;
  while (--t >= 0) {
    int n, k;
    cin >> n >> k;
    map<int, int> mii;
    while (--n >= 0) {
      int a;
      cin >> a;
      ++mii[a];
    }
    cout << sol(k, mii) << "\n";
  }
}