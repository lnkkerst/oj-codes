#include <algorithm>
#include <cstdio>
#define MAXN 55

int f[MAXN][MAXN][MAXN][MAXN], a[MAXN][MAXN], n, m;

int max(int x, int y) { return x > y ? x : y; }

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 1; k <= n; k++)
        for (int l = j + 1; l <= m; l++)
          f[i][j][k][l] =
              max(max(max(f[i][j - 1][k - 1][l], f[i - 1][j][k][l - 1]),
                      f[i][j - 1][k][l - 1]),
                  f[i - 1][j][k - 1][l]) +
              a[i][j] + a[k][l];
  printf("%d", f[n][m - 1][n - 1][m]);
  return 0;
}