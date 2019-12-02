#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  s.push_back(';');
  vector<string> n;
  vector<string> o;
  for (size_t i = 0; i < s.size(); ++i) {
    bool only_number = true;
    for (size_t l = i; i < s.size(); ++i) {
      if (s[i] == ',' || s[i] == ';') {
        if (i == (l + 1) && s[l] == '0') {
          n.push_back(string(s.cbegin() + l, s.cbegin() + i));
        } else if (only_number && i > l && s[l] != '0') {
          n.push_back(string(s.cbegin() + l, s.cbegin() + i));
        } else {
          o.push_back(string(s.cbegin() + l, s.cbegin() + i));
        }
        break;
      } else {
        only_number &= (s[i] >= '0' && s[i] <= '9');
      }
    }
  }
  if (n.empty()) {
    cout << "-\n";
  } else {
    cout << "\"" << n.front();
    for (size_t i = 1; i < n.size(); ++i) cout << ',' << n[i];
    cout << "\"\n";
  }
  if (o.empty()) {
    cout << "-\n";
  } else {
    cout << "\"" << o.front();
    for (size_t i = 1; i < o.size(); ++i) cout << ',' << o[i];
    cout << "\"\n";
  }
  return 0;
}
