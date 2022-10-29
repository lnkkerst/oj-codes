#include <cstdio>
#define MAXN 100005

int main() {
  int e[MAXN][MAXN], dis[MAXN], book[MAXN], m, n, s, u, v, min;
  const int inf = 99999999;

  scanf("%d%d%d", &n, &m, &s);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i == j)
        e[i][j] = 0;
      else
        e[i][j] = inf;

  for (int i = 1; i <= m; i++) {
    int t1, t2, t3;

    scanf("%d%d%d", &t1, &t2, &t3);

    e[t1][t2] = t3;
  }

  for (int i = 1; i <= n; i++) {
    dis[i] = e[s][i];
    book[i] = 0;
  }

  book[s] = 1;

  for (int i = 1; i <= n - 1; i++) {
    min = inf;

    for (int j = 1; j <= n; j++)
      if (book[j] == 0 && dis[j] < min) {
        min = dis[j];
        u = j;
      }

    book[u] = 1;

    for (v = 1; v <= n; v++)
      if (e[u][v] < inf)
        if (dis[v] > dis[u] + e[u][v])
          dis[v] = dis[u] + e[u][v];
  }

  for (int i = 1; i <= n; i++)
    if (dis[i] == inf)
      printf("2147483647 ");
    else
      printf("%d ", dis[i]);

  return 0;
}