#include <iostream>
using namespace std;

bool lucky(int const& n, int const& m) {
  if (n >= m) {
    if (n % m == 0) {
      return true;
    } else {
      return lucky(n, m * 10 + 4) || lucky(n, m * 10 + 7);
    }
  } else {
    return false;
  }
}

int main() {
  int n;
  cin >> n;
  if (lucky(n, 4) || lucky(n, 7))
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
  return 0;
}