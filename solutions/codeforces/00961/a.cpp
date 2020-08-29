/* Problemset 961 - Problem A
 * https://codeforces.com/problemset/problem/961/A
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T get() {
  T t;
  cin >> t;
  return t;
}

int main() {
  vector<int> t(get<int>(), 0);
  for (int m = get<int>(); m > 0; --m) {
    ++t[get<size_t>() - 1];
  }
  cout << *min_element(t.cbegin(), t.cend()) << '\n';
}
