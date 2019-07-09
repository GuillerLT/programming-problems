#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct city {
  size_t i;
  int c;
};

long long dist(vector<city> const& cs, city const& c, int const& k) {
  long long dist = 0LL;
  for (size_t i = 0; i < cs.size(); ++i)
    dist += abs((long long)cs[i].c - (long long)c.c);
  if (dist > (long long)k) {
    return dist - (long long)k;
  } else {
    return ((long long)k - dist) % 2;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<city> cs(n, city());
  for (size_t i = 0; i < (size_t)n; ++i) {
    city& c = cs[i];
    c.i = i + 1;
    cin >> cs[i].c;
  }
  sort(cs.begin(), cs.end(),
       [](city const& c1, city const& c2) -> bool { return c1.c < c2.c; });
  size_t ib = cs.size() / 2;
  long long db = dist(cs, cs[ib], k);
  for (int i = (int)cs.size() / 2 + 1; i < (int)cs.size(); ++i) {
    if (cs[i].c == cs[i - 1].c) {
      if (i - 1 == ib && cs[i].i < cs[ib].i) ib = i;
    } else {
      long long const d = dist(cs, cs[i], k);
      if (d <= db) {
        if (d < db || cs[i].i < cs[ib].i) {
          ib = i;
          db = d;
        }
      } else if (d > 1L) {
        break;
      }
    }
  }
  for (int i = (int)cs.size() / 2 - 1; i >= 0; --i) {
    if (cs[i].c == cs[i + 1].c) {
      if (i + 1 == ib && cs[i].i < cs[ib].i) ib = i;
    } else {
      long long const d = dist(cs, cs[i], k);
      if (d <= db) {
        if (d < db || cs[i].i < cs[ib].i) {
          ib = i;
          db = d;
        }
      } else if (d > 1L) {
        break;
      }
    }
  }
  cout << cs[ib].i << " " << db << "\n";
  return 0;
}