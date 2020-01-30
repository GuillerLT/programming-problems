#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int mins;
  cin >> mins;
  mins += stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
  string h = to_string(mins / 60 % 24);
  while(h.size() < 2) h = '0' + h;
  string m = to_string(mins % 60);
  while(m.size() < 2) m = '0' + m;
  cout << h << ':' << m << '\n';
  return 0;
}
