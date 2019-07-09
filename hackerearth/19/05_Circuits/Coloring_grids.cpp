#include <iostream>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  if (n != 2) {
    cout << k << "\n";
  } else {
    cout << k * k << "\n";
  }
  return 0;
}
