#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int d(vector<int> const& contador, int const& indice, int const& bal) {
  int ad = 0;
  int i;
  for (i = 0; i < indice; ++i) ad += abs(contador[i] - bal);
  for (; i < 26; ++i) ad += contador[i];
  return ad;
}

int main() {
  int t;
  cin >> t;
  while (--t >= 0) {
    // Cadena
    string s;
    cin >> s;
    // Contadores
    vector<int> contador(('Z' - 'A' + 1), 0);
    for (char const& c : s) ++contador[c - 'A'];
    sort(contador.begin(), contador.end(),
         [](int const& x, int const& y) -> bool { return x > y; });
    // Posibilidades
    vector<int> p;
    for (int i = 1; i <= 26; ++i)
      if (s.size() % i == 0) p.push_back(i);
    // Diferencias
    int bd = (s.size() - 1) * 2;
    for (int const& i : p) {
      int const ad = d(contador, i, s.size() / i);
      if (ad < bd) bd = ad;
    }
    cout << (bd / 2) << '\n';
  }
  return 0;
}