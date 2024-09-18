#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define int long long

constexpr int MOD = 998244353;

int qpow(int x, int k, int p = MOD) {
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
  return res;
}

int inv(int x) {
  return qpow(x, MOD - 2);
}
int frac(int x, int y) {
  return x * inv(y) % MOD;
}

int dengb(int x, int gb, int xs) {
  int tmp = frac(x * ((1 - qpow(gb, xs)) % MOD + MOD) % MOD,
                 ((1 - gb) % MOD + MOD) % MOD);
  return tmp % MOD;
}

void solve() {
  int n, m, ans = 1;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int res = ((1 - frac(1, qpow(26, i))) % MOD + MOD) % MOD;
    ans = ans + dengb(1, res, n);
    ans %= MOD;
  }

  int tmp = 26;
  int ans2 = 1;
  while (m) {
    int res = min(tmp, n);
    ans2 = ans2 % MOD + (res) % MOD;
    ans2 %= MOD;
    tmp = tmp * 26;
    if (tmp >= n) {
      tmp = n;
    }
    // tmp %= MOD;
    m--;

    //  n -= res;
  }

  cout << ans2 << " " << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
