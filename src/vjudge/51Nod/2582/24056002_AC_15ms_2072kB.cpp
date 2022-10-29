#include <algorithm>
#include <cctype>
#include <cstdio>

int n, a[500010], s, ans = 0x7fffffff;

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  s = read(), n = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read();
  int l = 0, r = 0, tot = 0;
  while (233) {
    while (r <= n && tot < s)
      tot += a[++r];
    if (tot < s)
      break;
    if (ans > r - l)
      ans = r - l;
    tot -= a[++l];
  }
  print(ans == 0x7fffffff ? 0 : ans);
  return 0;
}