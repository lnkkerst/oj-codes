#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double tot = 0;
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    tot += x;
  }
  cout << ((int)ceil((double)tot / n + 0.5));
  return 0;
}