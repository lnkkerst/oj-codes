#include <algorithm>
#include <cstdio>

typedef long long LL;
#define gc                                                                     \
  pa == pb && (pb = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pb)       \
      ? EOF                                                                    \
      : *pa++
static char buf[100000], *pa(buf), *pb(buf);
inline LL readint() {
  LL x = 0;
  char c = gc;
  while (c < '0' || c > '9')
    c = gc;
  for (; c >= '0' && c <= '9'; c = gc)
    x = x * 10 + (c & 15);
  return x;
}

int main() {
  int t = readint();
  while (t--) {
    int n = readint(), m = readint();
    if (n == 1) {
      int x = readint();
      printf("%d %d\n", x, x);
      continue;
    }
    int tl = 0, tr = 0;
    for (int i = 1; i <= n; ++i) {
      int x = readint();
      tl += x - 1;
      tr += m - x;
    }
    printf("%d %d\n", m - std::min(m, tr + 1) + 1, std::min(m, tl + 1));
  }
  return 0;
}