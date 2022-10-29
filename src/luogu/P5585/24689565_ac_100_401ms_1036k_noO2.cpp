#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

struct homework {
  int x, w, t;
  int pay;
} hw[6000];

int x, w, n, dp[6000 << 1];

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

bool cmp(homework a, homework b) { return a.t > b.t; }

#undef int
int main() {
#define int unsigned long long
  x = read(), w = read(), n = read();
  for (int i = 1; i <= n; ++i)
    hw[i].x = read(), hw[i].w = read(), hw[i].t = read();
  sort(hw + 1, hw + n + 1, cmp);
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (hw[i].w >= w)
      dp[w] = min(dp[w], hw[i].x);
    else
      for (int j = hw[i].w; j <= w + hw[i].w; ++j)
        dp[j] = min(dp[j], dp[j - hw[i].w] + hw[i].x);
    hw[i].pay = 1e18;
    for (int j = w; j <= (w << 1); ++j)
      hw[i].pay = min(hw[i].pay, dp[j]);
  }
  for (int i = n; i >= 1; --i) {
    int pay = hw[i].pay * (hw[i].t - hw[i + 1].t);
    if (x >= pay)
      x -= pay;
    else {
      printf("%lld %lld\n", hw[i + 1].t + x / hw[i].pay, x % hw[i].pay);
      return 0;
    }
  }
  printf("%lld %lld\n", hw[1].t, x);
  return 0;
}