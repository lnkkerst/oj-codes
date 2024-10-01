#include <bits/stdc++.h>
using namespace std;

int n, m;
char c[1001][1001];
int f[1001][1001], ans[100001];

void dfs(int x, int y, bool ch, int cnt) {
  if (x < 1 || x > n || y < 1 || y > n || f[x][y] != -1
      || c[x][y] - '0' != ch) {
    return;
  }
  f[x][y] = cnt, ++ans[cnt];
  dfs(x + 1, y, !ch, cnt);
  dfs(x - 1, y, !ch, cnt);
  dfs(x, y + 1, !ch, cnt);
  dfs(x, y - 1, !ch, cnt);
}

int main() {
  cin >> n >> m;
  memset(f, -1, sizeof(f));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    if (f[x][y] == -1) {
      dfs(x, y, c[x][y] - '0', i);
    } else {
      ans[i] = ans[f[x][y]];
    }
  }
  for (int i = 1; i <= m; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
