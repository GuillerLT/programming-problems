/* Problemset 678 - Problem C
 * https://codeforces.com/problemset/problem/678/C
 */

#include <algorithm>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
  while (b != 0) {
    long long const tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

long long lcm(long long const a, long long const b) {
  return a * b / gcd(a, b);
}

int main() {
  long long n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  long long rb = n / lcm(a, b);
  long long red = n / a - rb;
  long long blue = n / b - rb;
  cout << (red * p + blue * q + rb * max(p, q)) << '\n';
  return 0;
}
