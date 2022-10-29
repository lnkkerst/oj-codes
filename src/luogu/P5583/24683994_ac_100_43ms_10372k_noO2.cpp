#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, d, s[50010], cnt[1001], c[3001][1001], num[50001], ansl, ansr,
    ansb = 1e9, anss;
bool b[50001], fd;
int read() {
  int ret;
  bool f;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = 1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return f ? -ret : ret;
}

#undef int
int main() {
#define int long long
  n = read(), m = read(), d = read();
  for (int i = 1; i <= d; ++i)
    b[read()] = 1;
  for (int i = 1; i <= n; ++i) {
    s[i] = read(), num[i] = read();
    for (int j = 1; j <= num[i]; ++j)
      c[i][j] = read();
  }
  int l = 1, r = 1, sum = 0, sumb = 0;
  while (n - l + 1) {
    while (n - r + 1) {
      bool f = 1, check = 1;
      for (int i = 1; i <= num[r]; ++i)
        if (!b[c[r][i]]) {
          f = 0;
          break;
        }
      for (int i = 1; i <= m; ++i)
        if (b[i] && !cnt[i]) {
          check = 0;
          break;
        }
      if (check && !f)
        break;
      for (int i = 1; i <= num[r]; ++i) {
        if (!b[c[r][i]])
          ++sumb;
        ++cnt[c[r][i]];
      }
      sum += s[r];
      ++r;
    }
    bool check = 1;
    for (int i = 1; i <= m; ++i)
      if (b[i] && !cnt[i]) {
        check = 0;
        break;
      }
    if (check) {
      fd = 1;
      if (ansb > sumb || (ansb == sumb && anss < sum))
        ansb = sumb, anss = sum, ansl = l, ansr = r - 1;
    }
    for (int i = 1; i <= num[l]; ++i) {
      --cnt[c[l][i]];
      if (!b[c[l][i]])
        --sumb;
    }
    sum -= s[l];
    l++;
  }
  if (!fd)
    printf("-1\n");
  else
    printf("%lld %lld\n", ansl, ansr);
  return 0;
}