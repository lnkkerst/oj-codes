#include <cctype>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
const int MAXN = 100010;

int mod;

struct Sg_mtree {
#define lc (x << 1)
#define rc (x << 1 | 1)
  int sum[MAXN << 2], tag[MAXN << 2], mul[MAXN << 2], a[MAXN];
  void update(int x) {
    sum[x] = (sum[lc] % mod + sum[rc] % mod) % mod;
  }
  void build(int l, int r, int x) {
    sum[x] = 0, tag[x] = 0, mul[x] = 1;
    if (l == r) {
      sum[x] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lc);
    build(mid + 1, r, rc);
    update(x);
  }
  void pushdown(int l, int r, int x) {
    int mid = (l + r) >> 1;
    mul[lc] *= mul[x], mul[lc] %= mod;
    mul[rc] *= mul[x], mul[rc] %= mod;
    tag[lc] *= mul[x], tag[lc] %= mod;
    tag[rc] *= mul[x], tag[rc] %= mod;
    sum[lc] *= mul[x], sum[lc] %= mod;
    sum[rc] *= mul[x], sum[rc] %= mod;
    mul[x] = 1;
    tag[lc] += tag[x], tag[lc] %= mod;
    tag[rc] += tag[x], tag[rc] %= mod;
    sum[lc] += (mid - l + 1) * tag[x], sum[lc] %= mod;
    sum[rc] += (r - mid) * tag[x], sum[rc] %= mod;
    tag[x] = 0;
  }
  int query(int a, int b, int l, int r, int x) {
    if (a <= l && b >= r) {
      return sum[x] % mod;
    }
    int mid = (l + r) >> 1, ret = 0;
    ;
    if (mul[x] != 1 || tag[x]) {
      pushdown(l, r, x);
    }
    if (a <= mid) {
      ret += query(a, b, l, mid, lc);
    }
    if (mid < b) {
      ret += query(a, b, mid + 1, r, rc);
    }
    return ret % mod;
  }
  void add(int a, int b, int v, int l, int r, int x) {
    if (a <= l && b >= r) {
      tag[x] += v, tag[x] %= mod;
      sum[x] += v * (r - l + 1), sum[x] %= mod;
      return;
    }
    int mid = (l + r) >> 1;
    if (mul[x] != 1 || tag[x]) {
      pushdown(l, r, x);
    }
    if (a <= mid) {
      add(a, b, v, l, mid, lc);
    }
    if (mid < b) {
      add(a, b, v, mid + 1, r, rc);
    }
    update(x);
  }
  void mullall(int a, int b, int v, int l, int r, int x) {
    if (a <= l && b >= r) {
      mul[x] *= v, mul[x] %= mod;
      tag[x] *= v, tag[x] %= mod;
      sum[x] *= v, sum[x] %= mod;
      return;
    }
    int mid = (l + r) >> 1;
    if (mul[x] != 1 || tag[x]) {
      pushdown(l, r, x);
    }
    if (a <= mid) {
      mullall(a, b, v, l, mid, lc);
    }
    if (b < mid) {
      mullall(a, b, v, mid + 1, r, rc);
    }
    update(x);
  }
} tree;

int read() {
  int ret, flag = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * flag;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

void writeline(int x) {
  print(x);
  putchar('\n');
}

void writespace(int x) {
  print(x);
  putchar(' ');
}

signed main() {
  int n = read(), m = read();
  mod = read();
  for (int i = 1; i <= n; ++i) {
    tree.a[i] = read();
  }
  tree.build(1, n, 1);
  while (m--) {
    int opt = read(), l = read(), r = read();
    if (opt == 1) {
      tree.mullall(l, r, read(), 1, n, 1);
    }
    if (opt == 2) {
      tree.add(l, r, read(), 1, n, 1);
    } else {
      print(tree.query(l, r, 1, n, 1)), putchar('\n');
    }
  }
  return 0;
}
