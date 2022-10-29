#include <iostream>
#define int long long
using namespace std;

int calc(int x) {
  int ans = x;
  for (int i = 2; i * i <= x; ++i) {
    if (!(x % i)) {
      ans = ans / i * (i - 1);
      while (!(x % i))
        x /= i;
    }
  }
  if (x > 1)
    ans = ans / x * (x - 1);
  return ans;
}

int qpow(int x, int k, int p) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret *= x;
    x *= x, k >>= 1;
    x %= p, ret %= p;
  }
  return ret;
}

int solve(int x) {
  if (x == 1)
    return 0;
  return qpow(2, solve(calc(x)) + calc(x), x);
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << solve(x) << endl;
  }
}