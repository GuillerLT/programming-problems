/* Problemset 792 - Problem C
 * https://codeforces.com/problemset/problem/792/C
 */

#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string number;
  cin >> number;
  int r = 0;
  array<vector<size_t>, 3> av;
  for (size_t i = number.size(); i > 0; --i) {
    int const& v = number[i - 1] % 3;
    if (av[v].size() < 2) {
      av[v].push_back(i - 1);
    }
    r = (r + v) % 3;
  }
  string n1, n2;
  if (r == 1) {
    if (av[1].size() >= 1 && number.size() > 1) {
      n1 = number;
      n1.erase(av[1][0], 1);
      n1.erase(0, min(n1.size() - 1, n1.find_first_not_of('0')));
    }
    if (av[2].size() >= 2 && number.size() > 2) {
      n2 = number;
      n2.erase(av[2][0], 1);
      n2.erase(av[2][1], 1);
      n2.erase(0, min(n2.size() - 1, n2.find_first_not_of('0')));
    }
  } else if (r == 2) {
    if (av[2].size() >= 1 && number.size() > 1) {
      n1 = number;
      n1.erase(av[2][0], 1);
      n1.erase(0, min(n1.size() - 1, n1.find_first_not_of('0')));
    }
    if (av[1].size() >= 2 && number.size() > 2) {
      n2 = number;
      n2.erase(av[1][0], 1);
      n2.erase(av[1][1], 1);
      n2.erase(0, min(n2.size() - 1, n2.find_first_not_of('0')));
    }
  } else {
    n1 = number;
    n1.erase(0, min(n1.size() - 1, n1.find_first_not_of('0')));
  }
  if (n1.size() >= n2.size()) {
    if (n1.empty())
      cout << "-1\n";
    else
      cout << n1 << '\n';
  } else {
    cout << n2 << '\n';
  }
  return 0;
}
