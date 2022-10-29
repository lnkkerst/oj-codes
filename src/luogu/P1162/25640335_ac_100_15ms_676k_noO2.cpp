#include <bits/stdc++.h>
using namespace std;

int n, m;
int e[31][31];
bool b[31][31];

void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || e[x][y] != 0 || b[x][y])
    return;
  e[x][y] = 2;
  b[x][y] = 1;
  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
  b[x][y] = 0;
}

int main() {
  cin >> n;
  m = n;
  bool f = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> e[i][j];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      if (e[i][j]) {
        dfs(i + 1, j + 1);
        f = 1;
        break;
      }
    if (f)
      break;
  }
  for (int i = 1; i <= n; ++i, cout << endl)
    for (int j = 1; j <= m; ++j)
      cout << e[i][j] << ' ';
  return 0;
}