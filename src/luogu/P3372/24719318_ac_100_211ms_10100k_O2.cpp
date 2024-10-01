#include <bits/stdc++.h>
#define MAXN 400010
#define int long long
using namespace std;

struct SmT {
#define lc x << 1
#define rc x << 1 | 1
  int ls, rs;
  int sum[MAXN], a[MAXN], tag[MAXN];
  SmT() {
    ls = 1, rs = 0;
    memset(sum, 0, sizeof(sum));
    memset(a, 0, sizeof(a));
    memset(tag, 0, sizeof(tag));
  }
  void read() {
    int ret;
    char ch;
    bool flag = 0;
    while (!isdigit(ch = getchar())) {
      (ch == '-') && (flag = true);
    }
    for (ret = ch - '0'; isdigit(ch = getchar()); ret = ret * 10 + ch - '0')
      ;
    a[++rs] = ret;
  }
  void update(int x) {
    sum[x] = sum[lc] + sum[rc];
  }
  void tbuild(int l, int r, int x) {
    if (l == r) {
      sum[x] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    tbuild(l, mid, lc);
    tbuild(mid + 1, r, rc);
    update(x);
  }
  void build() {
    tbuild(ls, rs, 1);
  }
  int tquery(int a, int b, int l, int r, int x) {
    if (a <= l && r <= b) {
      return sum[x];
    }
    down(l, r, x);
    int mid = (l + r) >> 1, ans = 0;
    if (a <= mid) {
      ans += tquery(a, b, l, mid, lc);
    }
    if (mid < b) {
      ans += tquery(a, b, mid + 1, r, rc);
    }
    return ans;
  }
  int query(int a, int b) {
    return tquery(a, b, ls, rs, 1);
  }
  void down(int l, int r, int x) {
    int mid = (l + r) >> 1;
    if (tag[x]) {
      tag[lc] += tag[x];
      tag[rc] += tag[x];
      sum[lc] += (mid - l + 1) * tag[x];
      sum[rc] += (r - mid) * tag[x];
      tag[x] = 0;
    }
  }
  void tadd(int a, int b, int v, int l, int r, int x) {
    if (a <= l && r <= b) {
      tag[x] += v;
      sum[x] += v * (r - l + 1);
      return;
    }
    down(l, r, x);
    int mid = (l + r) >> 1;
    if (a <= mid) {
      tadd(a, b, v, l, mid, lc);
    }
    if (mid < b) {
      tadd(a, b, v, mid + 1, r, rc);
    }
    update(x);
  }
  void add(int a, int b, int v) {
    tadd(a, b, v, ls, rs, 1);
  }
} smt;

int read() {
  int ret;
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = true);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret = ret * 10 + ch - '0')
    ;
  return flag ? -ret : ret;
}

#undef int
int main() {
#define int long long
  int n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    smt.read();
  }
  smt.build();
  while (m--) {
    int opt = read();
    if (opt == 1) {
      int x = read(), y = read(), v = read();
      smt.add(x, y, v);
    } else {
      int x = read(), y = read();
      printf("%lld\n", smt.query(x, y));
    }
  }
  return 0;
}
