#include <iostream>
#define int long long
using namespace std;

signed main() {
  int x;
  cin >> x;
  int ans = x;
  for (int i = 2; i * i <= x; ++i) {
    if (!(x % i)) {
      ans = ans / i * (i - 1);
      while (!(x % i)) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    ans = ans / x * (x - 1);
  }
  cout << ans;
  return 0;
}
