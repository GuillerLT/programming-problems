#include <iostream>
#include <vector>

using namespace std;

int sol(long long n) {
  int i = 0;
  while (n != 1) {
    n >>= 1;
    ++i;
  }
  if ((i % 4) != 1 || i == 1)
    return (i % 4);
  else
    return 9;
}

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    long long n;
    cin >> n;
    cout << sol(n) << "\n";
  }
}