/* Problemset 1027 - Problem C
 * https://codeforces.com/problemset/problem/1027/C
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int get() {
  int i;
  scanf("%d", &i);
  return i;
}

int main() {
  for (int t = get(); t > 0; --t) {
    map<int, int> freq;
    for (int n = get(); n > 0; --n) {
      ++freq[get()];
    }
    vector<int> pairs;
    for (auto it = freq.begin(); it != freq.end(); it = freq.erase(it)) {
      if (it->second >= 2) {
        pairs.push_back(it->first);
        if (it->second >= 4) {
          pairs.push_back(it->first);
        }
      }
    }
    long long a_best, b_best,
        p2_best = 20002LL * 20002LL,
        s_best = 10000LL;
    for (size_t i = 1; i < pairs.size(); ++i) {
      long long const a = pairs[i - 1],
                      b = pairs[i],
                      p2 = (2 * a + 2 * b) * (2 * a + 2 * b),
                      s = a * b;
      if (p2_best * s >= p2 * s_best) {
        a_best = a;
        b_best = b;
        p2_best = p2;
        s_best = s;
      }
    }
    cout << a_best << ' ' << a_best << ' '
         << b_best << ' ' << b_best << '\n';
  }
  return 0;
}
