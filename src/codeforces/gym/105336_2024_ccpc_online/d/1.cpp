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

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length();
  s = " " + s;
  t = " " + t;
  vector<vector<vector<int>>> dp(
      n + 10, vector<vector<int>>(m + 10, vector<int>(m + 10)));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = j; k <= m; ++k) {
        if (j == k) {
          if (t[j] == s[i]) {
            dp[i][j][k] = 1;
          }
        }

        dp[i][j][k] += dp[i - 1][j][k] * 2 % MOD;
        dp[i][j][k] %= MOD;

        for (int u = j; u <= k - 1; ++u) {
          dp[i][j][k] += dp[i - 1][j][u] * dp[i - 1][u + 1][k] % MOD;
          dp[i][j][k] %= MOD;

          if (t[u] == s[i] && u != j && u != k) {
            dp[i][j][k] += dp[i - 1][j][u - 1] * dp[i - 1][u + 1][k] % MOD;
          }
          dp[i][j][k] %= MOD;
        }
        if (t[j] == s[i]) {
          dp[i][j][k] += dp[i - 1][j + 1][k];
          dp[i][j][k] %= MOD;
        }
        if (t[k] == s[i]) {
          dp[i][j][k] += dp[i - 1][j][k - 1];
          dp[i][j][k] %= MOD;
        }
        dp[i][j][k] %= MOD;
      }
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     for (int k = j; k <= m; ++k) {
  //       cout << i << ' ' << j << ' ' << k << ": " << dp[i][j][k] << endl;
  //     }
  //   }
  // }
  cout << dp[n][1][m] << endl;
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
