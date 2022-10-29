#include <cmath>
#include <iostream>

void solve() {
  int a, b, ans = 0;
  std::cin >> a >> b;
  a = abs(a - b);
  ans += a / 5;
  a %= 5;
  ans += a / 2;
  a %= 2;
  ans += a;
  std::cout << ans << std::endl;
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}