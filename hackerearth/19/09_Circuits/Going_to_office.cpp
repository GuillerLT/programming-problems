#include <iostream>

using namespace std;

int main() {
  long long distance, cfkm, nkm, clkm, speed, cbase, cmin, ckm;
  cin >> distance >> cfkm >> nkm >> clkm >> speed >> cbase >> cmin >> ckm;
  long long const online = cfkm + max(distance - nkm, 0LL) * clkm;
  long long const classic = cbase + (distance / speed) * cmin + distance * ckm;
  // cout << online << "\n";
  // cout << classic << "\n";
  if (online <= classic)
    cout << "Online Taxi\n";
  else
    cout << "Classic Taxi\n";
  return 0;
}