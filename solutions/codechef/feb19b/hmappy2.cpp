/* Contest FEB19B - Problem HMAPPY2
 * https://www.codechef.com/FEB19B/problems/HMAPPY2
 */

#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
  while (b != 0ull) {
    unsigned long long const r = a % b;
    a = b;
    b = r;
  }
  return a;
}

unsigned long long lcm(unsigned long long const& a,
                       unsigned long long const& b) {
  return (a * b) / gcd(a, b);
}

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    unsigned long long n, a, b, c, k;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> k;
    if ((n / a + n / b - 2ull * (n / lcm(a, b))) >= k)
      cout << "Win\n";
    else
      cout << "Lose\n";
  }
  return 0;
}