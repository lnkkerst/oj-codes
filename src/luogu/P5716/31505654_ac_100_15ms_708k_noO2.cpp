#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (233) {
    if ((b & 1 && b != 11) || b == 12)
      cout << 31;
    else if (b == 2)
      cout << 28 + ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0);
    else
      cout << 30;
  }
}