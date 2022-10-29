#include <bits/stdc++.h>

using namespace std;

int n, m;
int f[110][110], a[110][110];
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int read() {
  int ret;
  char ch;
  bool f = 0;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = 1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return f ? -ret : ret;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int dp(int i, int j) {
  if (f[i][j] > 1)
    return f[i][j];
  for (int k = 0; k < 4; ++k) {
    int x = i + dx[k], y = j + dy[k];
    if (x >= 1 && x <= n && y >= 1 && y <= m)
      if (a[x][y] < a[i][j])
        f[i][j] = max(f[i][j], dp(x, y) + 1);
  }
  return f[i][j];
}

int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      a[i][j] = read();
      f[i][j] = 1;
    }
  int ans = -1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      ans = max(dp(i, j), ans);
  printf("%d", ans);
  return 0;
}