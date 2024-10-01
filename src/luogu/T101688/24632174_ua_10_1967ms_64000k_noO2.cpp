#include <algorithm>
#include <cctype>
#include <cstdio>

int n, a[13001], ans, dp[13001][13001];

int read() {
  int ret;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = 1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return flag ? -ret : ret;
}

int max(int x, int y) {
  return x > y ? x : y;
}

int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  for (int i = 1; i <= n; ++i) {
    dp[i][i] = a[i];
    for (int j = i + 1; j <= n; ++j) {
      dp[i][j] = max(dp[i][j - 1] + a[j], a[j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    int maxdp = dp[i][i];
    for (int j = i; j <= n; ++j) {
      maxdp = max(maxdp, dp[i][j]);
      ans += maxdp < 0 ? 0 : maxdp;
    }
  }
  printf("%d\n", ans);
}
