#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (count(s.cbegin(), s.cend(), 'z') * 3 == s.size()) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}