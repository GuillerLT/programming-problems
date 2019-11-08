#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> vb(n, false);
  vector<int> vl, vr;
  while (--m >= 0) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      for (int i = l; i < r; ++i) {
        vb[i] = true;
      }
    } else {
      vl.push_back(l);
      vr.push_back(r);
    }
  }
  bool ok = true;
  for (int i = 0; i < vl.size(); ++i) {
    bool verdad = false;
    for (int j = vl[i]; j < vr[i]; ++j) {
      if (!vb[j]) {
        verdad = true;
        break;
      }
    }
    if (!verdad) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES\n";
    int anterior = n + 1;
    for (int i = 0; i < n; ++i) {
      if (vb[i]) {
        cout << ++anterior << " ";
      } else {
        cout << --anterior << " ";
      }
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}