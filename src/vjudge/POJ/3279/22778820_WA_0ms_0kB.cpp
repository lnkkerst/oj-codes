#include <cstdio>

int n, m;
bool e[16][16], t[16][16];
int ansn = (int)1e9, ans[16][16], atmp[16][16], cnt;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool check() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (t[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}

void change(int x, int y) {
  ++atmp[x][y], ++cnt;
  t[x][y] = !t[x][y];
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
      t[nx][ny] = !t[nx][ny];
    }
  }
}

void work(int stus) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      t[i][j] = e[i][j], atmp[i][j] = 0;
    }
  }
  cnt = 0;
  for (int i = 1; i <= m; ++i, stus >>= 1) {
    if (stus & 1) {
      change(1, i);
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (t[i - 1][j]) {
        change(i, j);
      }
    }
  }
  if (check() && cnt < ansn) {
    ansn = cnt;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        ans[i][j] = atmp[i][j];
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char ch = getchar();
      while (ch != '1' && ch != '0') {
        ch = getchar();
      }
      e[i][j] = ch - '0';
    }
  }
  for (int i = 0; i < 1 << n; ++i) {
    work(i);
  }
  if (ansn == (int)1e9) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  for (int i = 1; i <= n; ++i, putchar('\n')) {
    for (int j = 1; j <= m; ++j, putchar(' ')) {
      printf("%d", ans[i][j]);
    }
  }
  return 0;
}
