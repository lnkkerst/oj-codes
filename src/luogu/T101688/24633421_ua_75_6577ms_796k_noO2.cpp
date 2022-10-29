#include <algorithm>
#include <cctype>
#include <cstdio>

int n, a[13001], ans, dp[13001][13001];

int read() {
  int ret;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (flag = 1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return flag ? -ret : ret;
}

int max(int x, int y) { return x > y ? x : y; }

int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read();
  for (int i = 1; i <= n; ++i) {
    int dp = a[i], maxdp = a[i];
    for (int j = i + 1; j <= n; ++j) {
      ans += maxdp < 0 ? 0 : maxdp;
      dp = max(dp + a[j], a[j]);
      maxdp = max(maxdp, dp);
    }
    ans += maxdp < 0 ? 0 : maxdp;
    ans %= (int)1e5;
  }
  printf("%d\n", ans);
  return 0;
}