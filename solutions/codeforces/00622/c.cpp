#include <array>
#include <cstdio> // TLE when using cout/cin

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  array<int, 200002> a, d;
  a[0] = -1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    // d[i] stores first index that does not have a value equal to a[i]
    // example: a { dummy 1 2 2 3 3 3 }
    //          d {       0 1 1 3 3 3 }
    if (a[i - 1] == a[i]) {
      d[i] = d[i - 1];
    } else {
      d[i] = i - 1;
    }
  }
  int l, r, x;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &l, &r, &x);
    if (x == a[r]) {
      if (l <= d[r]) {
        printf("%d\n", d[r]);
      } else {
        printf("-1\n");
      }
    } else {
      printf("%d\n", r);
    }
  }
  return 0;
}
