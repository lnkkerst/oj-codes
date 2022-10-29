#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int x = 1;
  while (n--) {
    if (x * 2 > x + k)
      x += k;
    else
      x *= 2;
  }
  cout << x;
  return 0;
}