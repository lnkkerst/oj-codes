#include <algorithm>
#include <cctype>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Mem {
  int s, e;
} a[100010];

int n, m, sum[100010], ans = 1;
int f[100010];

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

bool cmp(Mem a, Mem b) { return a.s > b.s; }

int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; ++i)
    a[i].s = read(), a[i].e = read(), ++sum[a[i].s];
  sort(a + 1, a + n + 1, cmp);
  for (int i = n; i >= 1; --i) {
    if (!sum[i])
      f[i] = f[i + 1] + 1;
    else
      for (int j = 1; j <= sum[i]; ++j) {
        if (f[i + a[ans].e] > f[i])
          f[i] = f[i + a[ans].e];
        ++ans;
      }
  }
  print(f[1]);
  return 0;
}