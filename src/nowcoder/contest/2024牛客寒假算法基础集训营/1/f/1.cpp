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
  for (int i = 1; i <= 1e6; ++i) {
    f[i] = f[i - 1] * i % MOD;
  }
}

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= MOD;
    }
    x *= x;
    x %= MOD;
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

void solve() {
  int n, m;
  cin >> n >> m;
  if (n < m) {
    cout << 0 << endl;
    return;
  }
  int x = 0;
  for (int i = 0; i <= m; ++i) {
    int t = C(m, i) % MOD * qmi(m - i, n) % MOD;
    if (i & 1) {
      x -= t;
    } else {
      x += t;
    }
  }
  x %= MOD;
  x += MOD;
  x %= MOD;
  cout << x * inv(f[m]) % MOD << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
