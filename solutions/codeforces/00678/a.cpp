/* Problemset 678 - Problem A
 * https://codeforces.com/problemset/problem/678/A
 */

#include <iostream>
#include <iterator>

using namespace std;

int main() {
  int const n = *istream_iterator<int>(cin);
  int const k = *istream_iterator<int>(cin);
  cout << n + k - n % k << '\n';
  return 0;
}
