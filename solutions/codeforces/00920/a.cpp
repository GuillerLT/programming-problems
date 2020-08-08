/* Problemset 920 - Problem A
 * https://codeforces.com/problemset/problem/920/A
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t = get<int>(); t--;) {
    vector<int> beds(get<size_t>(), 201);
    for (int k = get<int>(); k--;) {
      beds[get<size_t>() - 1] = 1;
    }
    inclusive_scan(
        beds.cbegin(), beds.cend(), beds.begin(),
        [](int prev, int curr) { return min(prev + 1, curr); }, 201);
    inclusive_scan(
        beds.crbegin(), beds.crend(), beds.rbegin(),
        [](int prev, int curr) { return min(prev + 1, curr); }, 201);
    cout << *max_element(beds.cbegin(), beds.cend()) << '\n';
  }
}
