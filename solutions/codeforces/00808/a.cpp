/* Problemset 808 - Problem A
 * https://codeforces.com/problemset/problem/808/A
 */

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string y;
  cin >> y;
  string ny = y;
  for_each(next(ny.begin()), ny.end(), [](char &c) { c = '0'; });
  if (ny.front() == '9') {
    ny.replace(0, 1, "10");
  } else {
    ++ny.front();
  }
  cout << stoi(ny) - stoi(y) << '\n';
  return 0;
}
