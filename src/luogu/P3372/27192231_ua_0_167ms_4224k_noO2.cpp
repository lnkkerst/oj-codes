#include <cstdio>
#include <iostream>

long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

const int MAXN = 100010;

int n, m;
long long a[MAXN];

struct SG_Tree {
#define mid (l + r >> 1)
  long long k[MAXN << 2], tag[MAXN << 2];
  inline void update(int n) { k[n] = k[n << 1] + k[n << 1 | 1]; }
  inline void pushdown(int n, int l, int r) {
    if (!tag[n])
      return;
    k[n << 1] += (mid - l + 1) * tag[n];
    k[n << 1 | 1] += (r - mid) * tag[n];
    tag[n << 1] += tag[n];
    tag[n << 1 | 1] += tag[n];
    tag[n] = 0;
  }
  void build(int n, int l, int r) {
    if (l == r) {
      k[n] = a[l];
      return;
    }
    build(n << 1, l, mid);
    build(n << 1 | 1, mid + 1, r);
    update(n);
  }
  void modify(int n, int l, int r, int L, int R, long long p) {
    if (l > R || r < L)
      return;
    if (l >= L && r <= R) {
      tag[n] += p;
      k[n] += (r - l + 1) * p;
      return;
    }
    pushdown(n, l, r);
  }
  long long query(int n, int l, int r, int L, int R) {
    if (l > R || r < L)
      return 0;
    if (l >= L && r <= R)
      return k[n];
    pushdown(n, l, r);
    return query(n << 1, l, mid, L, R) + query(n << 1 | 1, mid + 1, r, L, R);
  }
} tree;

int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  tree.build(1, 1, n);
  for (int i = 1, opt, l, r, k; i <= m; i++) {
    opt = read(), l = read(), r = read();
    if (opt == 1) {
      k = read();
      tree.modify(1, 1, n, l, r, k);
    } else
      printf("%lld\n", tree.query(1, 1, n, l, r));
  }
  return 0;
}