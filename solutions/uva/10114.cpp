/* Problem 10114
 * https://onlinejudge.org/external/101/10114.pdf
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  while (true) {
    int duration;
    cin >> duration;
    if (duration < 0) break;
    float down;
    cin >> down;
    float amount;
    cin >> amount;
    float car = amount + down;
    float monthly = amount / duration;
    vector<float> dep(duration + 1);
    int records;
    cin >> records;
    while (--records >= 0) {
      int m;
      float d;
      cin >> m >> d;
      for (int i = m; i < duration; ++i) dep[i] = d;
    }
    int m = 0;
    while (true) {
      car -= car * dep[m];
      if (amount < car) {
        cout << m << " month";
        if (m != 1) cout << "s";
        cout << "\n";
        break;
      }
      amount -= monthly;
      ++m;
    }
  }
  return 0;
}