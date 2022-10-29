#include <cstdio>
#define int long long
#define MAXN 110
#define MOD % 9999973;
int n, m;
int dp[MAXN][MAXN][MAXN];
void solve() {
  dp[0][0][0] = 1;
  scanf("%lld%lld", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; j + k <= m; k++)
        if (dp[i][j][k]) {
          int tmp = m - j - k;
          dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) MOD if (tmp >= 1)
              dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] + dp[i][j][k] * (tmp))
                  MOD if (j >= 1) dp[i + 1][j - 1][k + 1] =
                      (dp[i + 1][j - 1][k + 1] +
                       dp[i][j][k] * j) MOD if (tmp >= 2) dp[i + 1][j + 2][k] =
                          (dp[i + 1][j + 2][k] +
                           dp[i][j][k] * tmp * (tmp - 1) / 2)
                              MOD if (tmp >= 1 && j >= 1) dp[i + 1][j][k + 1] =
                                  (dp[i + 1][j][k + 1] + dp[i][j][k] * tmp * j)
                                      MOD if (j >= 2) dp[i + 1][j - 2][k + 2] =
                                          (dp[i + 1][j - 2][k + 2] +
                                           dp[i][j][k] * j * (j - 1) / 2) MOD
        }
}
void res() {
  int ans = 0;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= m - i; j++)
      ans = (ans + dp[n][i][j]) MOD printf("%lld\n", ans);
}
#undef int
int main() {
#define int long long
  solve();
  res();
  return 0;
}