#include <iostream>
using namespace std;

bool pd(int x) {
  if (x == 1) {
    return 0;
  }
  if (x == 2) {
    return 1;
  }
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int l, r, ans = 0;
  cin >> l >> r;
  for (int i = l; i <= r; ++i) {
    if (pd(i)) {
      ++ans;
    }
  }
  cout << ans;
  return 0;
}
