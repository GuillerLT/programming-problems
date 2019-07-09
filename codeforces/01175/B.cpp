#include <iostream>
#include <vector>

using namespace std;

int main() {
  int l;
  cin >> l;
  long long const of = (1LL << 32LL) - 1LL;
  long long s = 0;
  vector<long long> m{1LL};
  while (--l >= 0) {
    string i;
    cin >> i;
    if (i == "for") {
      long long nm;
      cin >> nm;
      nm *= m.back();
      if (nm < m.back() || nm > of) {
        m.push_back(0LL);
      } else {
        m.push_back(nm);
      }
    } else if (i == "end") {
      m.pop_back();
    } else {
      long long ns = s + m.back();
      if (m.back() == 0 || ns < s || ns > of) {
        cout << "OVERFLOW!!!\n";
        return 0;
      } else {
        s = ns;
      }
    }
  }
  cout << s << "\n";
  return 0;
}