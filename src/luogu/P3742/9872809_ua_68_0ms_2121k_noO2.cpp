#include <iostream>
using namespace std;
int main() {
  char x[100], y[100], z[100];
  int n;
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    if (y[i] > x[i]) {
      cout << "-1";
      return 0;
    } else if (y[i] < x[i]) {
      z[i] = y[i];
    } else if (y[i] = x[i]) {
      z[i] = x[i] + 1;
    }
  }
  cout << z;
  return 0;
}