#include <iostream>

using namespace std;

int main() {
  while (true) {
    int l;
    cin >> l;
    if (l == 0) break;
    int p = 0;
    // 0 +x
    // 1 -x
    // 2 +y
    // 3 -y
    // 4 +z
    // 5 -z
    while (--l > 0) {
      string s;
      cin >> s;
      if (s == "+y") {
        switch (p) {
          case 0:
            p = 2;
            break;
          case 1:
            p = 3;
            break;
          case 2:
            p = 1;
            break;
          case 3:
            p = 0;
            break;
        }
      } else if (s == "-y") {
        switch (p) {
          case 0:
            p = 3;
            break;
          case 1:
            p = 2;
            break;
          case 2:
            p = 0;
            break;
          case 3:
            p = 1;
            break;
        }
      } else if (s == "+z") {
        switch (p) {
          case 0:
            p = 4;
            break;
          case 1:
            p = 5;
            break;
          case 4:
            p = 1;
            break;
          case 5:
            p = 0;
            break;
        }
      } else if (s == "-z") {
        switch (p) {
          case 0:
            p = 5;
            break;
          case 1:
            p = 4;
            break;
          case 4:
            p = 0;
            break;
          case 5:
            p = 1;
            break;
        }
      }
    }
    switch (p) {
      case 0:
        cout << "+x\n";
        break;
      case 1:
        cout << "-x\n";
        break;
      case 2:
        cout << "+y\n";
        break;
      case 3:
        cout << "-y\n";
        break;
      case 4:
        cout << "+z\n";
        break;
      case 5:
        cout << "-z\n";
        break;
    }
  }
  return 0;
}