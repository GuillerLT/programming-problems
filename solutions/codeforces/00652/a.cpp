/* Problemset 652 - Problem A
 * https://codeforces.com/problemset/problem/652/A
 */

#include <iostream>
#include <iterator>

using namespace std;

int main() {
  istream_iterator<int> isit(cin);
  int h1 = *isit++;
  int const h2 = *isit++;
  int const d = *isit++;
  int const n = *isit++;
  h1 += d * 8;
  if (h1 >= h2) {
    cout << "0\n";
  } else if (n >= d) {
    cout << "-1\n";
  } else {
    int const t = ((h2 - h1) / (12 *(d - n))) + !!((h2 - h1) % (12 *(d - n)));
    cout << t << endl;
  }
  return 0;
}
