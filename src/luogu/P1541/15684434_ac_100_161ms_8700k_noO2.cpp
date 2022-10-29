#include <cstdio>
#define MAXN 41

int max(int x, int y) { return x > y ? x : y; }

int main() {
  int f[MAXN][MAXN][MAXN][MAXN], g[5], a[351], n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  f[0][0][0][0] = a[1];
  for (int i = 1; i <= m; i++) {
    int t;
    scanf("%d", &t);
    g[t]++;
  }
  for (int i = 0; i <= g[1]; i++)
    for (int j = 0; j <= g[2]; j++)
      for (int k = 0; k <= g[3]; k++)
        for (int l = 0; l <= g[4]; l++) {
          int tmp = 1 + i + j * 2 + k * 3 + l * 4;
          if (i)
            f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k][l] + a[tmp]);
          if (j)
            f[i][j][k][l] = max(f[i][j][k][l], f[i][j - 1][k][l] + a[tmp]);
          if (k)
            f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k - 1][l] + a[tmp]);
          if (l)
            f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l - 1] + a[tmp]);
        }

  printf("%d", f[g[1]][g[2]][g[3]][g[4]]);

  return 0;
}