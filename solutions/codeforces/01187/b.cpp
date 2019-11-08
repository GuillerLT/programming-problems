#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  string s;
  cin >> n >> s >> m;
  vector<vector<int>> vvi(size_t('z' - 'a' + 1), vector<int>());
  for (int i = 0; i < n; ++i) {
    vvi[size_t(s[i] - 'a')].push_back(i);
  }
  while (--m >= 0) {
    vector<int> vi(size_t('z' - 'a' + 1), 0);
    string t;
    cin >> t;
    int res = 0;
    for (int i = 0; i < t.size(); ++i) {
      size_t const tmp = size_t(t[i] - 'a');
      res = max(res, vvi[tmp][vi[tmp]++]);
    }
    cout << res + 1 << "\n";
  }
}