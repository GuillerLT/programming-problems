/* Problemset 598 - Problem C
 * https://codeforces.com/problemset/problem/598/C
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

auto PI = acos(-1.0L);

long double myatan2(long double const y, long double const x) {
  return atan2(-y, -x) + PI;
}

int main() {
  int n;
  cin >> n;
  vector<tuple<long double, int>> v(n + 1);
  for (int i = 1; i <= n; ++i) {
    long double x, y;
    cin >> x >> y;
    v[i] = make_tuple(myatan2(y, x), i);
  }
  sort(v.begin() + 1, v.end());
  v.front() = v.back();
  int i1, i2;
  long double min_angle = 4.0L * PI;
  for (int i = 1; i < v.size(); ++i) {
    long double angle = abs(get<0>(v[i - 1]) - get<0>(v[i]));
    if(angle > PI) angle = 2 * PI - angle;
    if (angle < min_angle) {
      min_angle = angle;
      i1 = get<1>(v[i]);
      i2 = get<1>(v[i - 1]);
    }
  }
  cout << i1 << ' ' << i2 << '\n';
  return 0;
}
