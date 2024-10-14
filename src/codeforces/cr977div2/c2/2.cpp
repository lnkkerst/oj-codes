#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

const int N = 2e5 + 5, SZ = N << 2, INF = 0x7fffffff;

int tn;
int tr[N];

struct data {
  int mx, mx2, mn, mn2, cmx, cmn, tmx, tmn, tad;
  long long sum;
} t[SZ];

void pushup(int u) {
  const int lu = u << 1, ru = u << 1 | 1;
  t[u].sum = t[lu].sum + t[ru].sum;
  if (t[lu].mx == t[ru].mx) {
    t[u].mx = t[lu].mx, t[u].cmx = t[lu].cmx + t[ru].cmx;
    t[u].mx2 = max(t[lu].mx2, t[ru].mx2);
  } else if (t[lu].mx > t[ru].mx) {
    t[u].mx = t[lu].mx, t[u].cmx = t[lu].cmx;
    t[u].mx2 = max(t[lu].mx2, t[ru].mx);
  } else {
    t[u].mx = t[ru].mx, t[u].cmx = t[ru].cmx;
    t[u].mx2 = max(t[lu].mx, t[ru].mx2);
  }
  if (t[lu].mn == t[ru].mn) {
    t[u].mn = t[lu].mn, t[u].cmn = t[lu].cmn + t[ru].cmn;
    t[u].mn2 = min(t[lu].mn2, t[ru].mn2);
  } else if (t[lu].mn < t[ru].mn) {
    t[u].mn = t[lu].mn, t[u].cmn = t[lu].cmn;
    t[u].mn2 = min(t[lu].mn2, t[ru].mn);
  } else {
    t[u].mn = t[ru].mn, t[u].cmn = t[ru].cmn;
    t[u].mn2 = min(t[lu].mn, t[ru].mn2);
  }
}

void push_add(int u, int l, int r, int v) {
  // 更新加法标记的同时，更新 $\min$ 和 $\max$ 标记
  t[u].sum += (r - l + 1ll) * v;
  t[u].mx += v, t[u].mn += v;
  if (t[u].mx2 != -INF) {
    t[u].mx2 += v;
  }
  if (t[u].mn2 != INF) {
    t[u].mn2 += v;
  }
  if (t[u].tmx != -INF) {
    t[u].tmx += v;
  }
  if (t[u].tmn != INF) {
    t[u].tmn += v;
  }
  t[u].tad += v;
}

void push_min(int u, int tg) {
  // 注意比较 $\max$ 标记
  if (t[u].mx <= tg) {
    return;
  }
  t[u].sum += (tg * 1ll - t[u].mx) * t[u].cmx;
  if (t[u].mn2 == t[u].mx) {
    t[u].mn2 = tg; // !!!
  }
  if (t[u].mn == t[u].mx) {
    t[u].mn = tg; // !!!!!
  }
  if (t[u].tmx > tg) {
    t[u].tmx = tg; // 更新取 $\max$ 标记
  }
  t[u].mx = tg, t[u].tmn = tg;
}

void push_max(int u, int tg) {
  if (t[u].mn > tg) {
    return;
  }
  t[u].sum += (tg * 1ll - t[u].mn) * t[u].cmn;
  if (t[u].mx2 == t[u].mn) {
    t[u].mx2 = tg;
  }
  if (t[u].mx == t[u].mn) {
    t[u].mx = tg;
  }
  if (t[u].tmn < tg) {
    t[u].tmn = tg;
  }
  t[u].mn = tg, t[u].tmx = tg;
}

void pushdown(int u, int l, int r) {
  const int lu = u << 1, ru = u << 1 | 1, mid = (l + r) >> 1;
  if (t[u].tad) {
    push_add(lu, l, mid, t[u].tad), push_add(ru, mid + 1, r, t[u].tad);
  }
  if (t[u].tmx != -INF) {
    push_max(lu, t[u].tmx), push_max(ru, t[u].tmx);
  }
  if (t[u].tmn != INF) {
    push_min(lu, t[u].tmn), push_min(ru, t[u].tmn);
  }
  t[u].tad = 0, t[u].tmx = -INF, t[u].tmn = INF;
}

void build(int u = 1, int l = 1, int r = tn) {
  t[u].tmn = INF, t[u].tmx = -INF; // 取极限
  if (l == r) {
    t[u].sum = t[u].mx = t[u].mn = tr[l];
    t[u].mx2 = -INF, t[u].mn2 = INF;
    t[u].cmx = t[u].cmn = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void add(int L, int R, int v, int u = 1, int l = 1, int r = tn) {
  if (R < l || r < L) {
    return;
  }
  if (L <= l && r <= R) {
    return push_add(u, l, r, v); // !!! 忘 return
  }
  int mid = (l + r) >> 1;
  pushdown(u, l, r);
  add(L, R, v, u << 1, l, mid), add(L, R, v, u << 1 | 1, mid + 1, r);
  pushup(u);
}

void tomin(int L, int R, int v, int u = 1, int l = 1, int r = tn) {
  if (R < l || r < L || t[u].mx <= v) {
    return;
  }
  if (L <= l && r <= R && t[u].mx2 < v) {
    return push_min(u, v);
  }
  int mid = (l + r) >> 1;
  pushdown(u, l, r);
  tomin(L, R, v, u << 1, l, mid), tomin(L, R, v, u << 1 | 1, mid + 1, r);
  pushup(u);
}

void tomax(int L, int R, int v, int u = 1, int l = 1, int r = tn) {
  if (R < l || r < L || t[u].mn >= v) {
    return;
  }
  if (L <= l && r <= R && t[u].mn2 > v) {
    return push_max(u, v);
  }
  int mid = (l + r) >> 1;
  pushdown(u, l, r);
  tomax(L, R, v, u << 1, l, mid), tomax(L, R, v, u << 1 | 1, mid + 1, r);
  pushup(u);
}

long long qsum(int L, int R, int u = 1, int l = 1, int r = tn) {
  if (R < l || r < L) {
    return 0;
  }
  if (L <= l && r <= R) {
    return t[u].sum;
  }
  int mid = (l + r) >> 1;
  pushdown(u, l, r);
  return qsum(L, R, u << 1, l, mid) + qsum(L, R, u << 1 | 1, mid + 1, r);
}

long long qmax(int L, int R, int u = 1, int l = 1, int r = tn) {
  if (R < l || r < L) {
    return -INF;
  }
  if (L <= l && r <= R) {
    return t[u].mx;
  }
  int mid = (l + r) >> 1;
  pushdown(u, l, r);
  return max(qmax(L, R, u << 1, l, mid), qmax(L, R, u << 1 | 1, mid + 1, r));
}

long long qmin(int L, int R, int u = 1, int l = 1, int r = tn) {
  if (R < l || r < L) {
    return INF;
  }
  if (L <= l && r <= R) {
    return t[u].mn;
  }
  int mid = (l + r) >> 1;
  pushdown(u, l, r);
  return min(qmin(L, R, u << 1, l, mid), qmin(L, R, u << 1 | 1, mid + 1, r));
}

struct Tree {
#define ls (u << 1)
#define rs (u << 1 | 1)

private:
  int n;
  vector<int> a, mi;

  void pushdown(int u, int len) {
    a[ls] += a[u];
    a[rs] += a[u];
    mi[ls] += a[u] * ((len + 1) >> 1);
    mi[rs] += a[u] * (len >> 1);
    a[u] = 0;
  }

  void pushup(int u) {
    mi[u] = min(mi[ls], mi[rs]);
  }

  void add(int l, int r, int L, int R, int x, int u) {
    int len = r - l + 1;
    if (l >= L && r <= R) {
      a[u] += x;
      mi[u] += len * x;
      return;
    }
    if (a[u]) {
      pushdown(u, len);
    }
    int mid = ((r - l) >> 1) + l;
    if (L <= mid) {
      add(l, mid, L, R, x, ls);
    }
    if (R > mid) {
      add(mid + 1, r, L, R, x, rs);
    }
    pushup(u);
  }

  int query(int l, int r, int L, int R, int u) {
    int len = r - l + 1;
    if (l >= L && r <= R) {
      return mi[u];
    }
    if (a[u]) {
      pushdown(u, len);
    }
    int mid = ((r - l) >> 1) + l, res = 1e12;
    if (L <= mid) {
      res = min(res, query(l, mid, L, R, ls));
    }
    if (R > mid) {
      res += min(res, query(mid + 1, r, L, R, rs));
    }
    return res;
  }

public:
  Tree(int _n): n(_n), a((_n + 2) * 4), mi((_n + 2) * 4) {}

  void add(int l, int r, int x) {
    return add(1, n, l, r, x, 1);
  }

  void set(int k, int x) {
    add(k, k, -query(k, k));
    add(k, k, x);
  }

  int query(int l, int r) {
    return query(1, n, l, r, 1);
  }

#undef ls
#undef rs
};

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n + 1);
  vector<int> b(m + 1);
  vector<int> pos(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  vector<int> vis(n + 1);
  vector<int> offset(m + 1);
  tn = m;
  for (int i = 1; i <= m; ++i) {
    tr[i] = 0;
  }
  build();
  for (int i = 1; i <= m; ++i) {
    offset[i] = offset[i - 1];
    if (vis[b[i]]) {
      ++offset[i];
    }
    vis[b[i]] = 1;
    add(i, i, i - pos[b[i]] - offset[i]);
  }

  // for (int i = 1; i <= m; ++i) {
  //   cout << qmin(i, i) << ' ';
  // }
  // cout << endl;

  vector<set<int>> bk(n + 1);
  for (int i = 1; i <= m; ++i) {
    bk[b[i]].insert(i);
  }

  cout << ((qmin(1, m) >= 0) ? "YA" : "TIDAK") << endl;

  while (q--) {
    int s, t;
    cin >> s >> t;

    add(s, s, pos[b[s]]);
    add(s, s, -pos[t]);

    if (s == *bk[b[s]].begin()) {
      if (bk[b[s]].size() >= 2) {
        add(*++bk[b[s]].begin(), m, 1);
      }
    } else {
      add(s, m, 1);
    }

    bk[b[s]].erase(s);

    if (bk[t].empty() || *bk[t].begin() > s) {
      if (!bk[t].empty()) {
        add(*bk[t].begin(), m, -1);
      }
    } else {
      add(s, m, -1);
    }

    bk[t].insert(s);

    b[s] = t;

    cout << ((qmin(1, n + m) >= 0) ? "YA" : "TIDAK") << endl;
    // for (int i = 1; i <= m; ++i) {
    //   cout << qmin(i, i) << ' ';
    // }
    // cout << endl;
    // cout << (qmin(1, m)) << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
