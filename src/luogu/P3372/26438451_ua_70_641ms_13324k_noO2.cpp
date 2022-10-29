#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = 500010;

int n, m, a[MAXN], bl[MAXN];
int blocks, cnt = 0, l[MAXN], r[MAXN], sum[MAXN], dlt[MAXN], maxa[MAXN];

void init() {
  blocks = int(sqrt((double)n));
  for (int i = 1; i <= n; i += blocks)
    l[++cnt] = i, r[cnt] = min(i + blocks - 1, n);
  for (int i = 1; i <= cnt; ++i)
    for (int j = l[i]; j <= r[i]; ++j)
      bl[j] = i, sum[i] += a[j], maxa[i] = max(maxa[i], j);
}

void assign(int x, int v) { a[x] += v, sum[bl[x]] += v; }

void assign_range(int x, int y, int v) {
  int lc = bl[x], rc = bl[y];
  if (lc == rc && l[lc] == x && l[rc] == y) {
    dlt[lc] = v;
    return;
  }
  for (int i = x; i <= r[lc]; ++i)
    assign(i, v);
  if (l[lc] > x && l[rc] < y)
    return;
  for (int i = l[rc]; i <= y; ++i)
    assign(i, v);
  for (int i = lc + 1; i < rc; ++i)
    dlt[i] += v;
}

int query(int x, int y) {
  int lc = bl[x], rc = bl[y], ret = 0;
  if (lc == rc)
    for (int i = x; i <= y; ++i)
      ret += a[i] + dlt[bl[i]];
  else {
    for (int i = x; i <= r[lc]; ++i)
      ret += a[i] + dlt[bl[i]];
    for (int i = lc + 1; i < rc; ++i)
      ret += sum[i] + dlt[i] * (r[i] - l[i] + 1);
    for (int i = l[rc]; i <= y; ++i)
      ret += a[i] + dlt[bl[i]];
  }
  return ret;
}

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
  n = read(), m = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read();
  init();
  for (int i = 1; i <= m; ++i) {
    int opt = read();
    if (opt == 1) {
      int x = read(), y = read(), k = read();
      assign_range(x, y, k);
    } else {
      int x = read(), y = read();
      print(query(x, y)), putchar('\n');
    }
  }
  return 0;
}