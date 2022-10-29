#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double eps = 1e-7;
  int x;
  while (cin >> x) {
    if (fabs(x - sqrt(x)) < eps)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}