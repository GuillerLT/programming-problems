#include <iostream>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  s1 += "1";
  s2 += "1";
  s1.erase(s1.cbegin(), s1.cbegin() + s1.find_first_not_of('0'));
  s2.erase(s2.cbegin(), s2.cbegin() + s2.find_first_not_of('0'));
  if (s1.size() < s2.size()) {
    cout << "<\n";
  } else if (s1.size() > s2.size()) {
    cout << ">\n";
  } else {
    auto const val = s1.compare(s2);
    if (val < 0) {
      cout << "<\n";
    } else if (val > 0) {
      cout << ">\n";
    } else {
      cout << "=\n";
    }
  }
  return 0;
}
