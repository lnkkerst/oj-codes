#include <cstdio>
#include <cstring>
#define int long long

const int MOD = 1000000007;
int dp[2][4501];
int n, m;
bool fl = 0;

signed main() {
  while (scanf("%lld%lld", &m, &n) != EOF) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; ++i) {
      dp[1][i] = 1;
    }
    dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i > j) {
          dp[i % 2][j] = dp[(i - 1) % 2][j] % MOD;
        } else {
          dp[i % 2][j] = (dp[i % 2][j - i] + dp[(i - 1) % 2][j]) % MOD;
        }
      }
    }
    if (fl) {
      puts("");
    }
    fl = 1;
    printf("%lld", dp[m % 2][n]);
  }
  return 0;
}
