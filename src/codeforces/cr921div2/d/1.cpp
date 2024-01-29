#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

constexpr int MOD = 1e9 + 7;

vector<int> f(1e6 + 1);

void init() {
  f[0] = 1;
  for (int i = 1; i <= (int)1e6; ++i) {
    f[i] = f[i - 1] * i % MOD;
  }
}

int qmi(int x, int k, int p = MOD) {
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
  return res % MOD;
}

int inv(int x) {
  return qmi(x, MOD - 2) % MOD;
}

int C(int n, int m) {
  return f[n] * inv(f[m] * f[n - m] % MOD) % MOD;
}

int S(int n, int m, int p) {
  int q = ((1 - p % MOD) % MOD + MOD) % MOD;
  return C(n, m) * qmi(p, m) % MOD * qmi(q, n - m) % MOD;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(m);
  int tot = 0;
  for (auto &i : a) {
    cin >> i >> i >> i;
    tot += i;
    tot %= MOD;
  }
  int c = n * (n - 1) / 2 % MOD;
  int p = 1 * inv(c) % MOD;
  int ans = 0;
  int x = tot;
  for (int i = 1; i <= k; ++i) {
    ans += S(k, i, p) * tot % MOD;
    ans %= MOD;
    x += m;
    x %= MOD;
    tot += x;
    tot %= MOD;
  }
  cout << ans << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
