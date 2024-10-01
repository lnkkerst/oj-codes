#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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

constexpr int MOD = 998244353;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    int su = 0;
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      su += a[i][j];
      su %= MOD;
    }
    ans = ans * (su + 1) % MOD;
  }
  int ansf = 0;
  for (int col = 1; col <= m; ++col) {
    vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    vector<int> a1(n + 1), a2(n + 1);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (j == col) {
          a1[i] += a[i][j];
          a1[i] %= MOD;
        } else {
          a2[i] += a[i][j];
          a2[i] %= MOD;
        }
      }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= i; ++j) {
        for (int k = 0; k <= i - j; ++k) {
          dp[i][j][k] = dp[i - 1][j][k];
          if (j > 0) {
            dp[i][j][k] += dp[i - 1][j - 1][k] * a1[i] % MOD;
            dp[i][j][k] %= MOD;
          }
          if (k > 0) {
            dp[i][j][k] += dp[i - 1][j][k - 1] * a2[i] % MOD;
            dp[i][j][k] %= MOD;
          }
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= n - i; ++j) {
        if (i > j) {
          ansf += dp[n][i][j];
          ansf %= MOD;
        }
      }
    }
  }
  cout << (ans - ansf - 1 + MOD) % MOD << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
