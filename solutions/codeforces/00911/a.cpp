/* Problemset 911 - Problem A
 * https://codeforces.com/problemset/problem/911/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>
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
  vector<int> a(get<size_t>());
  copy_n(istream_iterator<int>(cin), a.size(), a.begin());
  int min_v = numeric_limits<int>::max(),  //
      d, min_d;
  for (int const ai : a) {
    if (ai < min_v) {
      min_v = ai;
      min_d = numeric_limits<int>::max();
      d = 0;
    } else {
      ++d;
      if (ai == min_v) {
        min_d = min(min_d, d);
        d = 0;
      } else {
      }
    }
  }
  cout << min_d << '\n';
  return 0;
}
