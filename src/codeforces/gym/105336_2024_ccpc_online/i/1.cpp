#pragma GCC optimize(2)
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

constexpr int MD = 1010;

int a[510];
int b[510];
int dp[510][510];
int p[MD + 100];

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);

  for (int i = 1; i <= MD; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (b[j] >= i) {
        ++p[i];
      }
    }
  }

  int ans = 0;

  for (int k = 1; k <= 501; ++k) {
    for (int i = 1; i <= n; ++i) {
      ++a[i];
    }

    int tmp1 = 0, tmp2 = 0;

    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; --i) {
      dp[i][0] = 1;

      for (int j = 1; j <= n - i + 1; ++j) {
        dp[i][j] =
            dp[i + 1][j - 1] * max(0ll, (p[a[i]] - j + 1)) % MOD + dp[i + 1][j];
        dp[i][j] %= MOD;
      }
    }
    for (int j = 1; j <= n; ++j) {
      tmp1 += dp[1][j];
      tmp1 %= MOD;
    }

    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; --i) {
      dp[i][0] = 1;

      for (int j = 1; j <= n - i + 1; ++j) {
        dp[i][j] = dp[i + 1][j - 1] * max(0ll, (p[a[i] + 1] - j + 1)) % MOD +
                   dp[i + 1][j];
        dp[i][j] %= MOD;
      }
    }
    for (int j = 1; j <= n; ++j) {
      tmp2 += dp[1][j];
      tmp2 %= MOD;
    }

    ans += ((tmp1 - tmp2) % MOD + MOD) % MOD * k % MOD;
    ans %= MOD;
  }
  cout << (ans % MOD + MOD) % MOD << endl;
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
