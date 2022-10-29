#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

bool e[31][31][31];
bool b[31][31][31];
int k, n, m, sx, sy, ex, ey, sk, ek;
int ans;
bool found = 0;

void dfs(int kk, int x, int y, int step) {

  if (kk == ek && x == ex && y == ey) {
    ans = step;
    found = 1;
    return;
  }
  if (found || e[kk][x][y] || b[kk][x][y] || kk < 1 || kk > k || x < 1 ||
      x > n || y < 1 || y > m)
    return;
  b[kk][x][y] = 1;
  dfs(kk - 1, x, y, step + 1);
  dfs(kk + 1, x, y, step + 1);
  dfs(kk, x + 1, y, step + 1);
  dfs(kk, x - 1, y, step + 1);
  dfs(kk, x, y + 1, step + 1);
  dfs(kk, x, y - 1, step + 1);
}

int main() {
  while (1) {
    scanf("%d%d%d", &k, &n, &m);
    if (!k && !n && !m)
      return 0;
    memset(e, 0, sizeof(e));
    memset(b, 0, sizeof(b));
    ans = -1, found = 0;
    for (int kk = 1; kk <= k; ++kk)
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
          char ch;
          cin >> ch;
          if (ch == 'S')
            sx = i, sy = j, sk = kk;
          if (ch == 'E')
            ex = i, ey = j, ek = kk;
          if (ch == '#')
            e[kk][i][j] = 1;
        }
    dfs(sk, sx, sy, 0);
    if (ans == -1)
      puts("Trapped!");
    else
      printf("Escaped in %d minute(s).\n", ans);
  }
}