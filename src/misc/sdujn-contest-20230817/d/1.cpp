#pragma GCC optimize(2)

#include <iostream>

using namespace std;

#define int long long

constexpr int MAXN = 100010;
constexpr int MOD = 998244353;

int fi[MAXN];

signed qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = res * x % p;
    }
    x = x * x % p;
    k >>= 1;
  }
  return res;
}

int inv(int x, int p = MOD) {
  if (fi[x]) {
    return fi[x];
  }
  return fi[x] = qmi(x, p - 2, p);
}

void solve() {
  int n, m;
  cin >> n >> m;
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans = ans * i % MOD;
  }
  --n;
  --m;
  for (int i = 1; i <= n; ++i) {
    ans = ans * i % MOD;
  }
  for (int i = 1; i <= m; ++i) {
    ans = ans * inv(i) % MOD;
  }
  for (int i = 1; i <= n - m; ++i) {
    ans = ans * inv(i) % MOD;
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
