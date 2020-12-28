/* Problemset 1469 - Problem C
 * https://codeforces.com/problemset/problem/1469/C
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

template <class T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  for (int t{get<int>()}; t > 0; --t) {
    int const n{get<int>()}, k{get<int>()};
    vector<int> ground(n);
    copy_n(istream_iterator<int>(cin), n, ground.begin());
    int min{ground.front()}, max{ground.front()};
    bool error = false;
    for (auto it{next(ground.cbegin())}; it != ground.cend(); ++it) {
      min = std::max(*it, min - k + 1);
      max = std::min(*it, max) + k - 1;
      error |= (max < min);
    }
    error |= (min != ground.back());
    cout << (error ? "no\n" : "yes\n");
  }
  return 0;
}
