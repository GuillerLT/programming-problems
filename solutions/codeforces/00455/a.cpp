/* Problemset 455 - Problem A
 * https://codeforces.com/problemset/problem/455/A
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  vector<long long> freq(100001, 0);
  for (size_t i = *istream_iterator<size_t>(cin); i > 0; --i) {
    size_t const ai = *istream_iterator<size_t>(cin);
    freq[ai] += ai;
  }
  for (size_t i = 2; i < 100001; ++i) {
    freq[i] = max(freq[i - 1], freq[i] + freq[i - 2]);
  }
  cout << freq.back() << '\n';
  return 0;
}
