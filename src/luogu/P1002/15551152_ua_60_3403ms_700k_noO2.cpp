#include <cstdio>
#define MAXN 21

bool a[MAXN][MAXN] = {0};
int n, m;
long long ans = 0;

void dfs(int x, int y) {
  if (x == n && y == m) {
    ans++;

    return;
  }

  if (x > n || y > m)
    return;

  a[x][y] = 1;

  if (a[x + 1][y] == 0)
    dfs(x + 1, y);

  if (a[x][y + 1] == 0)
    dfs(x, y + 1);

  a[x][y] = 0;
}

int main() {
  scanf("%d%d", &n, &m);

  int x, b;

  scanf("%d%d", &x, &b);

  a[x][b] = 1;
  a[x + 1][b + 2] = 1;
  a[x + 2][b + 1] = 1;
  a[x - 2][b + 1] = 1;
  a[x - 1][b + 2] = 1;
  a[x - 2][b - 1] = 1;
  a[x - 1][b - 2] = 1;
  a[x + 1][b - 2] = 1;
  a[x + 2][b - 1] = 1;

  dfs(0, 0);

  printf("%lld", ans);

  return 0;
}