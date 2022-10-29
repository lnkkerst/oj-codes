#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define int __int128_t
using namespace std;

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (fl = -1);
  ret = ch - '0';
  while (isdigit(ch = getchar()))
    ret *= 10, ret += ch - '0';
  return ret * fl;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int a[233], dp[233][233];
int n, m, ans = 0;

signed main() {
  n = read(), m = read();
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= m; ++i)
      a[i] = read();
    for (int i = 0; i <= m; ++i)
      for (int j = 1; i + j <= m; ++j)
        dp[j][i + j] = max(2 * dp[j + 1][i + j] + 2 * a[j],
                           2 * dp[j][i + j - 1] + 2 * a[i + j]);
    ans += dp[1][m];
    memset(dp, 0, sizeof(dp));
  }
  print(ans);
  return 0;
}