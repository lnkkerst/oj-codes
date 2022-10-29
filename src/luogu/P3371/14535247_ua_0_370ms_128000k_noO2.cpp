#include <cstdio>
#define MAXN 10001
int main() {
  int map[MAXN][MAXN], book[MAXN] = {0}, dis[MAXN], n, m, s;
  const int inf = 99999999;

  scanf("%d%d%d", &n, &m, &s);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i == j)
        map[i][j] = 0;
      else
        map[i][j] = inf;

  for (int i = 1; i <= m; i++) {
    int x, y, z;

    scanf("%d%d%d", &x, &y, &z);

    map[x][y] = z;
  }

  for (int i = 1; i <= n; i++)
    dis[i] = map[s][i];

  book[s] = 1;

  for (int i = 1; i <= n - 1; i++) {
    int min = inf, u;

    for (int j = 1; j <= n; j++)
      if (!book[j] && dis[j] < min) {
        min = dis[j];
        u = j;
      }

    if (u == 0)
      break;

    book[u] = 1;

    for (int v = 1; v <= n; v++)
      if (dis[v] > dis[u] + map[u][v])
        dis[v] = dis[u] + map[u][v];
  }

  for (int i = 1; i <= n; i++)
    if (dis[i] == inf)
      printf("2147483647 ");
    else
      printf("%d ", dis[i]);

  return 0;
}