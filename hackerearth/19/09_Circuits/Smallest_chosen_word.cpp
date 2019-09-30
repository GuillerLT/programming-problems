#include <iostream>
#include <vector>

using namespace std;

int main() {
  size_t x, y, z;
  cin >> x >> y >> z;
  string r, s, t;
  if (x > 0) cin >> r;
  cout << r;
  if (y > 0) cin >> s;
  if (z > 0) {
    cin >> t;
    bool insert_equal = false;
    for(size_t i = 0; i < t.size(); ++i) {
      if(t[i] != t.front()) {
        insert_equal = (t[i] > t.front());
        break;
      }
    }
    vector<char> vc;
    vc.push_back(t.front());
    for (size_t i = y - 1; i < y; --i) {
      char const& c = s[i];
      if(c < vc.back()) {
        vc.push_back(c);
        insert_equal = true;
      } else if(c == vc.back() && insert_equal) {
        vc.push_back(c);
      }
    }
    for(size_t i = vc.size() - 1; i > 0; --i) {
      cout << vc[i];
    }
  }
  cout << t << "\n";
  return 0;
}