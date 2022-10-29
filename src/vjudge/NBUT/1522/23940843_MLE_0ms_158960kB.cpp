#include <cstdio>
#define int long long

const int MOD = 1000000007;
int dp[4501][4501];
int n, m;

signed main() {
  scanf("%lld%lld", &m, &n);
  for (int i = 1; i <= n; ++i)
    dp[i][1] = 1;
  for (int i = 1; i <= m; ++i)
    dp[1][i] = dp[0][i] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (i >= j)
        dp[i][j] = (dp[i][j - 1] + dp[i - j][j]) % MOD;
      else
        dp[i][j] = dp[i][j - 1] % MOD;
  printf("%lld", dp[n][m]);
  return 0;
}