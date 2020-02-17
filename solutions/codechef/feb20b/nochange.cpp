#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int a, b, c, p;

bool foo(multiset<int> monedas, int total) {
  if (total > p) {
    int diff = total - p;
    if (diff >= *monedas.cbegin()) {
      return false;
    } else {
      // copy(monedas.cbegin(), monedas.cend(), ostream_iterator<int>(cout, " "));
      // cout << endl;
      return true;
    }
  } else {
    bool r = false;
    multiset<int> m;
    m = monedas;
    m.insert(a);
    r |= foo(m, total + a);
    m = monedas;
    m.insert(b);
    r |= foo(m, total + b);
    m = monedas;
    m.insert(c);
    r |= foo(m, total + c);
    return r;
  }
}

int main() {
  srand(time(NULL));
  int i = 0;
  while (true) {
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    c = rand() % 10 + 1;
    if (a == b || a == c || b == c) continue;
    p = rand() % 25 + 1;
    if (!foo(multiset<int>{}, 0)) {
      cout << endl;
      cout << a << endl;
      cout << b << endl;
      cout << c << endl;
      cout << p << endl;
      cout << endl;
      return 0;
    } else {
      cout << i++ << endl;
    }
  }
}
