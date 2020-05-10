/* Problemset 884 - Problem B
 * https://codeforces.com/problemset/problem/884/B
 */

#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;

int main() {
  istream_iterator<long long> it(cin);
  long long const n = *it;
  long long const x = *++it;
  cout << ((x - n == accumulate(++it, istream_iterator<long long>(), -1))
               ? "YES\n"
               : "NO\n");
  return 0;
}
