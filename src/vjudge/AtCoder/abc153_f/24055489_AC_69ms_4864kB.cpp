#include <algorithm>
#include <cctype>
#include <cstdio>
#define int long long

struct Monster {
  int x, h, dam;
} a[200010];

int n, d, s, ans = 0;

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

bool cmp(Monster a, Monster b) { return a.x < b.x; }

signed main() {
  n = read(), d = read(), s = read();
  for (int i = 1; i <= n; ++i)
    a[i].x = read(), a[i].h = read();
  std::sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    a[i].dam += a[i - 1].dam;
    int l = i, r = i + (d << 1);
    if (r > n)
      r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (a[mid].x <= a[i].x + (d << 1))
        l = mid;
      else
        r = mid - 1;
    }
    int tmp = (a[i].h - a[i].dam * s + s - 1) / s;
    if (tmp < 0)
      continue;
    ans += tmp, a[i].dam += tmp, a[l + 1].dam -= tmp;
  }
  print(ans);
  return 0;
}