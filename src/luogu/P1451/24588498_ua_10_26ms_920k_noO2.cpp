#include <cstdio>

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int a[101][101], n, m, ans;

void dfs(int i, int j) {
  if (i < 1 || i > n || j < 1 || j > m || !a[i][j])
    return;
  a[i][j] = 0;
  for (int k = 0; k < 4; ++k)
    dfs(i + dx[k], j + dy[k]);
}

int main() {
  scanf("%d%d", &n, &m);
  getchar();
  for (int i = 1; i <= n; ++i, getchar())
    for (int j = 1; j <= m; ++j) {
      char ch = getchar();
      a[i][j] = ch - '0';
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j]) {
        dfs(i, j);
        ++ans;
      }
  printf("%d\n", ans);
  return 0;
}