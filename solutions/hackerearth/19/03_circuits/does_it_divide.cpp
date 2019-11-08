#include <iostream>
using namespace std;

void factors(long long n) {
  cout << n << ": ";
  for (int i = 2; i <= n; ++i) {
    while (n % i == 0) {
      cout << i << " ";
      n /= i;
    }
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  for (int j = 1; j < t; ++j) {
    long long n = j;
    // cin >> n;
    long long sum = n * (n + 1) / 2;
    for (int i = n; i >= 2; --i) {
      if (sum % i == 0) {
        sum /= i;
        if (sum == 1) break;
      }
    }
    if (sum == 1) {
      cout << "\n"
           << "Y"
           << "\n";
      factors(j);
      factors(j * (j + 1) / 2);
    } else {
      cout << "\n"
           << "N"
           << "\n";
      factors(j);
      factors(j * (j + 1) / 2);
    }
  }
}