#include <iostream>
using namespace std;
int main() {
  int i;
  cin >> i;
  if (i == 2 || i % 2 == 1)
    cout << "NO"
         << "\n";
  else
    cout << "YES"
         << "\n";
  return 0;
}