#include <cstdio>
#define MAXN 65

int dis[MAXN][MAXN], n, m;
bool b[MAXN][MAXN][MAXN] = {0};

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        dis[i][j] = 0;
      } else {
        dis[i][j] = 99999999;
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    int t1, t2;

    scanf("%d%d", &t1, &t2);

    dis[t1][t2] = 1;
    b[t1][t2][0] = 1;
  }

  for (int k = 1; k <= MAXN - 1; k++) {
    for (int i = 1; i <= n; i++) {
      for (int t = 1; t <= n; t++) {
        for (int j = 1; j <= n; j++) {
          if (b[i][t][k - 1] && b[t][j][k - 1]) {
            b[i][j][k] = 1;
            dis[i][j] = 1;
          }
        }
      }
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dis[i][j] > dis[i][k] + dis[k][j]) {
          dis[i][j] = dis[i][k] + dis[k][j];
        }
      }
    }
  }

  printf("%d", dis[1][n]);

  return 0;
}
