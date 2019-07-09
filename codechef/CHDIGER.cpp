#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    string N;
    char d;
    cin >> N >> d;
    vector<vector<string>> dp(N.size(), vector<string>(N.size()));
    for (size_t k = 0; k < N.size(); ++k) {
      char const& c = N[k];
      dp[k][k] = (c < d) ? c : d;
      // cout << k << "\n";
      // cout << k << "\n";
      // cout << dp[k][k] << "\n" << "\n";
    }
    for (size_t k = 1; k < N.size(); ++k) {
      for (size_t j = 0; j < N.size() - k; ++j) {
        size_t i = j + k;
        string& s = dp[j][i];
        if (dp[j][i - 1].compare(dp[j + 1][i]) > 0) {
          s = dp[j + 1][i] + d;
        } else {
          s = dp[j][j] + dp[j + 1][i];
          // cout << s << "\n";
          for (size_t p = j + 1; p < i; ++p) {
            string t(dp[j][p] + dp[p + 1][i]);
            // cout << t << "\n";
            if (s.compare(t) >= 0) {
              s = t;
            }
          }
        }
        // cout << j << "\n";
        // cout << i << "\n";
        // cout << s << "\n" << "\n";
      }
    }
    cout << dp[0][N.size() - 1] << "\n";
  }
  return 0;
}