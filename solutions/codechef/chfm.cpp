#include <iostream>
#include <memory>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

struct coins {
  int value;
  int index;
  coins(int const& value = 0, int const& index = 0)
      : value(value), index(index) {}
};

struct cmp {
  bool operator()(coins const& i, coins const& j) const {
    return i.value < j.value;
  }
};

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    int n;
    cin >> n;
    long long avg = 0LL;
    set<coins, cmp> cs;
    for (int i = 1; i <= n; ++i) {
      int a;
      cin >> a;
      avg += a;
      cs.insert(coins(a, i));
    }
    if (avg % n != 0) {
      cout << "Impossible\n";
    } else {
      avg /= n;
      auto p = cs.find(coins(avg));
      if (p == cs.end()) {
        cout << "Impossible\n";
      } else {
        cout << p->index << "\n";
      }
    }
  }
  return 0;
}