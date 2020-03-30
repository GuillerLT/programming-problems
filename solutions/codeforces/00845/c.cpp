/* Problemset 845 - Problem C
 * https://codeforces.com/problemset/problem/845/C
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> shows(n);
  for_each(shows.begin(), shows.end(),
           [](auto& show) { cin >> show.first >> show.second; });
  sort(shows.begin(), shows.end());
  for_each(shows.begin(), shows.end(), [](auto const& show)  {
    static int tv1 = -1, tv2 = -1;
    if (show.first > tv1) {
      tv1 = show.second;
    } else if (show.first > tv2) {
      tv2 = show.second;
    } else {
      cout << "NO\n";
      exit(0);
    }
  });
  cout << "YES\n";
  return 0;
}
