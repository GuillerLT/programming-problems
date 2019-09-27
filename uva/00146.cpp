#include <algorithm>
#include <iostream>

using namespace std;

bool next_permutation(string &s) {
  if (s.size() <= 1) return false;
  auto it1 = s.rbegin();
  auto it2 = next(it1);
  while (*it2 >= *it1) {
    ++it2;
    ++it1;
    if (it2 == s.crend()) return false;
  }
  auto it3 = s.rbegin();
  while (*it2 >= *it3) ++it3;
  swap(*it2, *it3);
  reverse(s.rbegin(), it2);
  return true;
}

int main() {
  while (true) {
    string s;
    cin >> s;
    if (s.size() == 1 && s.front() == '#') return 0;
    if (next_permutation(s))  // std::next_permutation(s.begin(), s.end())
      cout << s << "\n";
    else
      cout << "No Successor\n";
  }
}
