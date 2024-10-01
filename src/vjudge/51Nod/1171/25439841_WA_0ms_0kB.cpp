#include <cmath>
#include <cstdio>
#include <iostream>
#define int long long
using namespace std;

typedef long long LL;
#define gc                                                               \
  pa == pb && (pb = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pb) \
    ? EOF                                                                \
    : *pa++
static char buf[100000], *pa(buf), *pb(buf);
inline LL readint() {
  LL x = 0;
  char c = gc;
  while (c < '0' || c > '9') {
    c = gc;
  }
  for (; c >= '0' && c <= '9'; c = gc) {
    x = x * 10 + (c & 15);
  }
  return x;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 10) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

signed main() {
  int n;
  n = readint();
  int i = sqrt(n), j = 0, j2 = 0, i2 = i * i;
  int ans[23333][2] = {0};
  int cnt = 0;
  while (i >= j) {
    while (i2 + j2 < n) {
      j2 += (j << 1 | 1);
      ++j;
    }
    if (i2 + j2 == n) {
      ans[++cnt][0] = j;
      ans[cnt][1] = i;
    }
    --i;
    i2 -= (i << 1 | 1);
  }
  if (!cnt) {
    puts("No Solution");
    return 0;
  }
  for (int i = 1; i <= cnt; ++i) {
    if (ans[i][0] <= ans[i][1]) {
      print(ans[i][0]);
      putchar(' ');
      print(ans[i][1]);
      puts("");
    }
  }
  return 0;
}
