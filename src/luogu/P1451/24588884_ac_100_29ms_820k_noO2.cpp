#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int a[101][101], n, m, ans;

void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || !a[x][y]) {
    return;
  }
  a[x][y] = 0;
  for (int k = 0; k < 4; ++k) {
    dfs(x + dx[k], y + dy[k]);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char ch;
      cin >> ch;
      a[i][j] = ch - '0';
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        dfs(i, j);
        ++ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
