#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char c;
    cin >> c;
    vector<int> distances;
    int last = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == c) {
        distances.push_back(i - last - 1);
        last = i;
      }
    }
    distances.push_back(n - last - 1);
    long long res = 0;
    // i : numero de coincidencias paquete
    for (int i = 1; i < distances.size(); ++i) {
      // j : indice primera coincidencia
      // k : indice ultima coincidencia
      for (int j = 0, k = j + i; k < distances.size(); ++j, ++k) {
        long long l = distances[j];
        long long r = distances[k];
        res += (l + 1) * (r + 1);
      }
    }
    cout << res << "\n";
  }
  return 0;
}