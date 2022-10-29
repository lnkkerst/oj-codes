#include <cstdio>

const int MOD = 1000000007;
int dp[4000][4000];
int n, m;

int main() {
  while (scanf("%d%d", &m, &n) != EOF) {
    for (int i = 1; i <= n; ++i)
      dp[i % 4000][1] = 1;
    for (int i = 1; i <= m; ++i)
      dp[1][i % 4000] = dp[0][i % 4000] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (i >= j)
          dp[i % 4000][j % 4000] =
              (dp[i % 4000][(j - 1) % 4000] + dp[(i - j) % 4000][j % 4000]) %
              MOD;
        else
          dp[i % 4000][j % 4000] = dp[i % 4000][(j - 1) % 4000] % MOD;
    printf("%d\n", dp[n % 4000][m % 4000]);
  }
  return 0;
}