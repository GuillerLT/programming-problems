/* Problemset 678 - Problem B
 * https://codeforces.com/problemset/problem/678/B
 */

#include <iostream>
#include <iterator>

using namespace std;

bool is_leap(int const y) {
  return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}

int main() {
  int y = *istream_iterator<int>(cin);
  bool const lo = is_leap(y);
  bool l = lo;
  int r = 0;
  do {
    r = (r + (l ? 2 : 1)) % 7;
    l = is_leap(++y);
  } while(r != 0 || l != lo);
  cout << y << '\n';
  return 0;
}
