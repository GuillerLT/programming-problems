#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    k++;
    if (n % k == 0)
      printf("Dishant\n");
    else
      printf("Arpa\n");
  }
  return 0;
}