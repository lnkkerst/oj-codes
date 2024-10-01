#include <iostream>
using namespace std;

bool pd(int x) {
  int res = 0, t = x;
  while (t) {
    res *= 10, res += t % 10, t /= 10;
  }
  return res == x;
}

int main() {
  int x;
  cin >> x;
  for (int i = 0;; ++i) {
    if (pd(x - i)) {
      cout << x - i;
      return 0;
    }
    if (pd(x + i)) {
      cout << x + i;
      return 0;
    }
  }
  return 0;
}
