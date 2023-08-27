#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

constexpr int MAXN = 5000010;
constexpr int MOD = (int)1e9 + 7;

int fact[MAXN], infact[MAXN];
int yp[MAXN], xp[MAXN], rxp[MAXN];

int fastPow(int x, int k, int p = MOD) {
  x %= MOD;
  int res = 1;
  while (k) {
    if (k & 1) {
      res = res * x % p;
    }
    x = x * x % p;
    k >>= 1;
  }
  return res % p;
}

int C(int m, int n, int p = MOD) {
  int res = (fact[n] * infact[n - m] % MOD) * infact[m] % MOD;
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
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
    xp[i] = xp[i - 1] * x % MOD;
    yp[i] = yp[i - 1] * y % MOD;
    rxp[i] = rxp[i - 1] * rx % MOD;
  }
  int m = ta;
  int ans = 0;
  for (int i = m; i <= n; ++i) {
    ans += calc(x, y, n, i);
    ans %= MOD;
  }
  cout << ((long long)ans) << endl;
  return 0;
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
