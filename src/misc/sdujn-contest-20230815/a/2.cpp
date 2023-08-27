
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

constexpr int MAXN = 6000010;
constexpr int MOD = (int)1e9 + 7;

int fact[MAXN], infact[MAXN];
int yp[MAXN], xp[MAXN], rxp[MAXN];

int fastPow(int x, int k, int p = MOD) {
  x %= MOD;
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= p;
    }
    x *= x;
    x %= p;
    k >>= 1;
  }
  return res % p;
}

int C(int m, int n, int p = MOD) {
  int res = 1;
  res *= fact[n];
  res %= MOD;
  res *= infact[n - m];
  res %= MOD;
  res *= infact[m];
  res %= MOD;
  return res;
}

void init() {
  fact[0] = infact[0] = 1;
  for (int i = 1; i <= MAXN - 1; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
    infact[i] = infact[i - 1] * fastPow(i, MOD - 2, MOD) % MOD;
  }
}

int calc(int x, int y, int n, int m) {
  int ans = C(m, n);
  ans %= MOD;
  ans *= xp[m] * fastPow(yp[m], MOD - 2, MOD) % MOD;
  ans %= MOD;
  x = y - x;
  m = n - m;

  ans *= rxp[m] * fastPow(yp[m], MOD - 2, MOD) % MOD;
  ans %= MOD;

  return ans;
}

signed main() {
  init();
  int n, r1, r2, r, a, h;
  cin >> n >> r1 >> r2 >> r >> a >> h;
  int ta = (h + a - 1) / a;
  if (ta > n) {
    cout << 0 << endl;
    return 0;
  }
  if (r1 + r >= r2) {
    cout << 1 << endl;
    return 0;
  }
  int x = r1 + r;
  int y = r2;
  x *= x;
  y *= y;
  int rx = y - x;
  xp[0] = yp[0] = rxp[0] = 1;
  for (int i = 1; i <= MAXN - 1; ++i) {
    xp[i] = xp[i - 1] * (x % MOD) % MOD;
    yp[i] = yp[i - 1] * (y % MOD) % MOD;
    rxp[i] = rxp[i - 1] * (rx % MOD) % MOD;
  }
  int m = ta;
  if (m > n / 2) {
    int ans = 0;
    for (int i = m; i <= n; ++i) {
      ans += calc(x, y, n, i);
      ans %= MOD;
    }
    return 0;
  } else {
    int ans = 0;
    for (int i = 0; i <= m - 1; ++i) {
      ans += calc(x, y, n, i);
      ans %= MOD;
    }
    ans = (1 - ans + MOD) % MOD;
    cout << ((long long)ans) << endl;
  }
  // cout << n << ' ' << m << ' ' << x << ' ' << y << endl;
  // int ans = C(m, n);
  // cout << ans << endl;
  // ans *= fastPow(x, m) * fastPow(fastPow(y, m), MOD - 2, MOD) % MOD;
  // ans %= MOD;
  // cout << ans << endl;
  // x = y - x;
  // m = n - m;
  //
  // ans *= fastPow(x, m) * fastPow(fastPow(y, m), MOD - 2, MOD) % MOD;
  // ans %= MOD;
  // cout << ans << endl;
}
